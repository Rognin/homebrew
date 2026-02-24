#pragma once
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_sheep_idle.h"
#include "bn_fixed_point.h"
#include "bn_camera_ptr.h"
#include <vector>

class sheep {
public:
    sheep(bn::fixed start_x, bn::fixed start_y, bn::camera_ptr& camera);

    void update();
    bn::fixed get_x() { return sprite.x(); }
    bn::fixed get_y() { return sprite.y(); }

private:

    bn::fixed x;
    bn::fixed y;

    bn::sprite_ptr sprite;
    bn::sprite_animate_action<4> idle_anim;
};