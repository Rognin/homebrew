#pragma once
#include "bn_fixed_point.h"
#include "sheep.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_string.h"
#include <vector>
#include "bn_sound_items.h"

class sheep_manager{

    struct spawn_point {
        bn::fixed x;
        bn::fixed y;
        bool occupied;
    };

public:
    sheep_manager(bn::camera_ptr& camera);

    void update(bn::fixed player_x, bn::fixed player_y);
    void spawn_one_sheep();
    int get_random_free_spawn_point_index();

    void on_sheep_collected(sheep collected_sheep);

    void update_counter();

private:

    std::vector<sheep> sheep_list;

    bn::camera_ptr& camera;

    int sheep_pickup_radius = 12; // in pixels

    int collected_count = 0;

    // counter display
    bn::sprite_text_generator text_generator;
    bn::vector<bn::sprite_ptr, 8> text_sprites;

    std::vector<spawn_point> spawn_points = {
        {bn::fixed(230), bn::fixed(65), false},    // column 1, row 8
        {bn::fixed(105), bn::fixed(-7), false},    // column 2, row 8
        {bn::fixed(184), bn::fixed(-71), false},    // column 3, row 8
        {bn::fixed(235), bn::fixed(-139), false},    // column 4, row 8
        {bn::fixed(-17), bn::fixed(-215), false},    // column 6, row 9
        {bn::fixed(-226), bn::fixed(-118), false},    // column 7, row 9
        {bn::fixed(-126), bn::fixed(-39), false},    // column 8, row 9
        {bn::fixed(15), bn::fixed(50), false},    // column 9, row 9
        {bn::fixed(229), bn::fixed(212), false},    // column 12, row 10
        {bn::fixed(117), bn::fixed(225), false},   // column 13, row 10
        {bn::fixed(-100), bn::fixed(206), false},   // column 14, row 10
        {bn::fixed(-234), bn::fixed(144), false},   // column 15, row 10
    };
};