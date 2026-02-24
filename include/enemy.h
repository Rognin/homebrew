#pragma once
#include "bn_fixed.h"
#include "bn_sprite_items_sheep_idle.h"
#include "bn_sprite_items_shepherd_idle.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"

class Enemy {
    public:

    Enemy();

    void initialize();
    void updateAnimation();

    int health;
    bn::fixed x;
    bn::fixed y;

    bn::optional<bn::sprite_ptr> sprite;
    bn::optional<bn::sprite_animate_action<4>> animation;

};