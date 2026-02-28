// Class that manages player animations based on the current state

#pragma once

#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_shepherd_idle.h"
#include "bn_sprite_items_shepherd_walk_spritesheet.h"
#include "bn_sprite_items_shepherd_jump_spritesheet.h"
#include "bn_sprite_items_shepherd_fall_spritesheet.h"
#include "bn_sprite_items_shepherd_attack_spritesheet.h"
#include "player_movement.h"

class player_animator {
public:
    player_animator(bn::sprite_ptr& player_sprite);

    void set_state(PlayerState state);

    void update();

private:
    bn::sprite_ptr& sprite;

    bn::sprite_animate_action<8> idle_anim;
    bn::sprite_animate_action<12> walk_anim;
    bn::sprite_animate_action<8> jump_anim;
    bn::sprite_animate_action<8> fall_anim;
    bn::sprite_animate_action<8> attack_anim;

    PlayerState currentState;
    PlayerState previousState;

    bool attack_active;
};