// Class that manages health display

#pragma once
#include "bn_sprite_ptr.h"
#include <vector>

class health_hud
{
public:
    health_hud(int starting_health);

    void set_health(int value);

private:
    int max_health;
    int current_health;
    std::vector<bn::sprite_ptr> hearts;
};