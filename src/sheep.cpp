#include "sheep.h"

sheep::sheep(bn::fixed start_x, bn::fixed start_y, bn::camera_ptr& camera) :
    x(start_x),
    y(start_y),
    sprite(bn::sprite_items::sheep_idle.create_sprite(x, y)),
    idle_anim(bn::create_sprite_animate_action_forever(sprite, 20,
        bn::sprite_items::sheep_idle.tiles_item(), 0,1,2,3))
{
    sprite.set_camera(camera);
}

void sheep::update() {
    idle_anim.update();
}