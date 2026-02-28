#include "player_animator.h"

    player_animator::player_animator(bn::sprite_ptr& player_sprite) : sprite(player_sprite),

        // Initialize animations
        idle_anim(bn::create_sprite_animate_action_forever(sprite, 30,
            bn::sprite_items::shepherd_idle.tiles_item(), 0,1,2,3,4,5,6,7)),

        walk_anim(bn::create_sprite_animate_action_forever(sprite, 4,
            bn::sprite_items::shepherd_walk_spritesheet.tiles_item(), 0,1,2,3,4,5,6,7,8,9,10,11)),

        jump_anim(bn::create_sprite_animate_action_once(sprite, 2,
            bn::sprite_items::shepherd_jump_spritesheet.tiles_item(), 0,1,2,3,4,5,6,7)),
            
        fall_anim(bn::create_sprite_animate_action_forever(sprite, 4,
            bn::sprite_items::shepherd_fall_spritesheet.tiles_item(), 0,1,2,3,4,5,6,7)),

        attack_anim(bn::create_sprite_animate_action_once(sprite, 2,
            bn::sprite_items::shepherd_attack_spritesheet.tiles_item(), 0,1,2,3,4,5,6,7)),

        currentState(IDLE),
        previousState(IDLE)
    {
        sprite.set_tiles(bn::sprite_items::shepherd_idle.tiles_item(), 0);
        attack_active = false;
    }

    void player_animator::set_state(PlayerState state) {
        currentState = state;
    }

    void player_animator::update() {

        // Attacking overrides other states, so if attack is active, force state to ATTACKING
        if(attack_active && currentState != ATTACKING) {
            currentState = ATTACKING;
        }
        
        // Switch animation if state changed
        if(currentState != previousState) {
            switch(currentState) {
                case IDLE:   idle_anim.reset();   break;
                case WALKING: walk_anim.reset(); break;
                case JUMPING: jump_anim.reset(); break;
                case FALLING: fall_anim.reset(); break;
                case ATTACKING:
                attack_anim.reset();
                attack_active = true;
                break;
                default: break;
            }
            previousState = currentState;
        }

        // Update the active animation
        switch(currentState) {
            case IDLE:
            idle_anim.update();
            break;
            case WALKING:
            walk_anim.update();
            break;
            case JUMPING: 
            if(!jump_anim.done()){
                jump_anim.update();
            } 
            break;
            case FALLING:
            fall_anim.update();
            break;
            case ATTACKING:
            if(attack_active){
                if(!attack_anim.done()){
                    attack_anim.update();
                } else {
                    attack_active = false;
                }
            }
            default: break;
        }
    }