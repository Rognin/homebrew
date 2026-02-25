#include "bn_core.h"
#include "bn_memory.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_frame1.h"
#include "bn_sprite_items_cloaked_idle_spritesheet.h"
#include "bn_sprite_items_sheep_idle.h"
#include "bn_sprite_items_shepherd_idle.h"
#include "bn_regular_bg_items_mountains_bg.h"
#include "bn_regular_bg_items_houses_bg.h"
#include "bn_regular_bg_items_test_level.h"

#include "bn_string.h"
#include <bn_string_view.h>
#include "bn_sprite_text_generator.h"
#include "common_variable_8x16_sprite_font.h"

#include "player_movement.h"
#include "player_animator.h"
#include "health_hud.h"
#include "sheep_manager.h"
#include "enemy.h"
#include "level.h"

#include "bn_music_items.h"

// Screen size: 240x160 pixels

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);
    bn::vector<bn::sprite_ptr, 32> text_sprites;

    // Create background
    bn::regular_bg_ptr mountains_bg = bn::regular_bg_items::mountains_bg.create_bg(0, 0);
    bn::regular_bg_ptr houses_bg = bn::regular_bg_items::houses_bg.create_bg(0, 0);
    
    Level test_level(Level::SpawnPoint{0, 0});
    test_level.load();

    bn::sprite_ptr idle_hero = bn::sprite_items::shepherd_idle.create_sprite(0, 30);
    idle_hero.set_horizontal_flip(false);

    
    bn::sprite_animate_action<8> idle_sheperd_anim = bn::create_sprite_animate_action_forever(
        idle_hero, 30, bn::sprite_items::shepherd_idle.tiles_item(), 0, 1, 2, 3, 4, 5, 6, 7
    );

    player_movement player = player_movement(); //TODO: pass the spawnpoint from the level
    player.set_collision_data(&test_level.get_collision_data());

    player_animator animator(idle_hero);
    health_hud hud(player.starting_health);

    // create camera
    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

    idle_hero.set_camera(camera);
    test_level.level_image.set_camera(camera);

    sheep_manager sheep_manager(camera);
    sheep_manager.spawn_initial_sheep();

    // music
    bn::music_items::calm_down.play(0.2, true);

    while(! bn::keypad::start_pressed())
        {
            player.handle_movement();
            player.update_state();

            animator.set_state(player.currentState);
            animator.update();

            idle_hero.set_horizontal_flip(player.facing_left);
            idle_hero.set_x(player.x);
            idle_hero.set_y(player.y);  

            bn::string<32> str;

            str.append(" ");
            str.append(bn::to_string<8>(player.debug_value_1));
            str.append(" ");
            str.append(bn::to_string<8>(player.debug_value_2));
            str.append(" ");
            str.append(bn::to_string<8>(player.debug_value_3));
            str.append(" ");
            str.append(bn::to_string<8>(player.debug_value_4));
            str.append(" ");
            str.append(bn::to_string<8>(player.on_ground ? 1 : 0));
            str.append(" ");
            str.append(bn::to_string<8>(player.on_slope ? 1 : 0));
            str.append(" ");

            text_sprites = {};
            text_generator.generate(-112, 72, str, text_sprites);
            // enemy.updateAnimation();

            // update camera
            camera.set_x(player.x);
            camera.set_y(player.y - 40);

            mountains_bg.set_x(-camera.x() / 4);
            houses_bg.set_x(-camera.x() / 2);
            test_level.level_image.set_x(0);

            sheep_manager.update(player.x, player.y);

            // temporary health debug
            if(bn::keypad::l_pressed()) {
                player.change_health(-1);
            }

            if(bn::keypad::r_pressed()) {
                player.reset_health();
            }

            // check if player died

            if(player.health <= 0) {
                player.respawn();
                sheep_manager.reset();
            }

            hud.set_health(player.health);

            bn::core::update();
        }
}
