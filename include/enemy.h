// Enemy class

#pragma once
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_wolf_enemy_idle.h"
#include "bn_sprite_items_wolf_enemy_walk.h"
#include "bn_sprite_animate_actions.h"
#include "bn_fixed.h"
#include "bn_camera_ptr.h"
#include "collision_utils.h"

class enemy {
public:
    // This creates the enemy at a specific spot
    enemy(bn::fixed start_x, bn::fixed start_y, bn::camera_ptr& camera);

    // This keeps the animation playing
    void update();

    // This checks if the enemy got hit
    void check_hit(bn::fixed player_attack_x, bn::fixed player_attack_y, bool player_attacking);

    void on_death();

    bool is_alive();

    bn::fixed get_x() { return sprite.x(); }
    bn::fixed get_y() { return sprite.y(); }

private:
    bn::fixed x;
    bn::fixed y;
    bn::sprite_ptr sprite;
    bn::sprite_animate_action<2> idle_anim;
    bn::sprite_animate_action<4> walk_anim;
    bool facing_left;
    int health;
    int starting_health = 3;
    int invincibility_timer = 0;
    int invincibility_frames = 30;

    // left-right movement
    bn::fixed initial_x;
    bn::fixed movement_range = 32;
    bn::fixed speed = 0.4;
};