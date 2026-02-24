#include "enemy.h"

Enemy::Enemy() {
    health = 100;
    x = 0;
    y = 0;
}

void Enemy::initialize(){
    sprite = bn::sprite_items::sheep_idle.create_sprite(0,0);
    animation.emplace(bn::create_sprite_animate_action_forever(
        *sprite, 30, bn::sprite_items::sheep_idle.tiles_item(), 0, 1, 2, 3
        ));
}

void Enemy::updateAnimation(){
    if(animation)
    animation->update();
}