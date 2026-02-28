#include "health_hud.h"
#include "bn_sprite_items_heart.h"

health_hud::health_hud(int starting_health) :
    max_health(starting_health),
    current_health(starting_health)
{
    // top-left of screen
    int start_x = -112;
    int start_y = -72;
    int spacing = 16;

    for(int i = 0; i < starting_health; i++)
    {
        bn::sprite_ptr heart = bn::sprite_items::heart.create_sprite(
            start_x + i * spacing,
            start_y
        );

        hearts.push_back(heart);
    }
}

void health_hud::set_health(int value)
{
    current_health = bn::clamp(value, 0, max_health);

    for(int i = 0; i < max_health; ++i)
    {
        hearts[i].set_visible(i < current_health);
    }
}