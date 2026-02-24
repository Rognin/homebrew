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
#include "enemy.h"
#include "level.h"

// Screen size: 240x160 pixels

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

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

    bn::sprite_ptr idle_sheep = bn::sprite_items::sheep_idle.create_sprite(112, -72);
    bn::sprite_animate_action<4> idle_sheep_anim = bn::create_sprite_animate_action_forever(
        idle_sheep, 30, bn::sprite_items::sheep_idle.tiles_item(), 0, 1, 2, 3
        );

    player_movement player = player_movement(); //TODO: pass the spawnpoint from the level
    player.set_collision_data(&test_level.get_collision_data());

    Enemy enemy = Enemy();
    // enemy.initialize();


    // create camera
    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

    idle_hero.set_camera(camera);
    test_level.level_image.set_camera(camera);

    while(! bn::keypad::start_pressed())
        {
            player.handle_movement();

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

            auto text_sprites = text_generator.generate_top_left<32>(0, 0, str);

            idle_sheperd_anim.update();
            idle_sheep_anim.update();
            // enemy.updateAnimation();

            // update camera
            camera.set_x(player.x);
            camera.set_y(player.y - 40);

            mountains_bg.set_x(-camera.x() / 4);
            houses_bg.set_x(-camera.x() / 2);
            test_level.level_image.set_x(0);
            enemy.x = camera.x();
            enemy.y = camera.y();

            bn::core::update();
        }
}
