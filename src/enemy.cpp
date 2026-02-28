#include "enemy.h"

enemy::enemy(bn::fixed start_x, bn::fixed start_y, bn::camera_ptr& camera) :
    x(start_x),
    y(start_y),
    initial_x(start_x),
    sprite(bn::sprite_items::wolf_enemy_idle.create_sprite(x, y)),
    idle_anim(bn::create_sprite_animate_action_forever(sprite, 20,
        bn::sprite_items::wolf_enemy_idle.tiles_item(), 0,1)),
    walk_anim(bn::create_sprite_animate_action_forever(sprite, 10,
        bn::sprite_items::wolf_enemy_walk.tiles_item(), 0,1,2,3)),
    facing_left(true)
{
    sprite.set_camera(camera);
    health = starting_health;
}

void enemy::update() {

    if(health <= 0) {
        return;
    }

    walk_anim.update();
    if (invincibility_timer > 0) {
        invincibility_timer--;
        sprite.set_visible((invincibility_timer / 4) % 2); // blinking effect when damaged
    } else {
        sprite.set_visible(true);
    }

    // left-right movement
    bn::fixed direction = facing_left ? -1 : 1;
    x += direction * speed;

    // Turn around at patrol limits
    if (x < initial_x - movement_range) {
        x = initial_x - movement_range;
        facing_left = false;
    }
    else if (x > initial_x + movement_range) {
        x = initial_x + movement_range;
        facing_left = true;
    }

    sprite.set_x(x);
    sprite.set_horizontal_flip(!facing_left);
}

void enemy::check_hit(bn::fixed player_attack_x, bn::fixed player_attack_y, bool player_attacking) {

    if(invincibility_timer > 0) {
        return;
    }

    // hardcoded hitboxes for now
    if (player_attacking && aabb_overlap(x - 16, y, 32, 16, player_attack_x, player_attack_y, 16, 16)) {
        health--;
        invincibility_timer = invincibility_frames;
        if (health <= 0) {
            on_death();
        }
    }
}

void enemy::on_death() {
    sprite.set_visible(false);
}

bool enemy::is_alive() {
    return health > 0;
}