#include "bn_sprite_ptr.h"
#include "bn_keypad.h"
#include <vector>
#include <cmath>

enum TileType {
    TILE_EMPTY = -1,
    TILE_SOLID = 0,

    // 45° slopes
    TILE_SLOPE_45_UP_RIGHT = 1,
    TILE_SLOPE_45_UP_LEFT  = 2,

    // 22.5° slopes
    TILE_SLOPE_22_UP_RIGHT_0 = 3,
    TILE_SLOPE_22_UP_RIGHT_1 = 4,
    TILE_SLOPE_22_UP_LEFT_0  = 5,
    TILE_SLOPE_22_UP_LEFT_1  = 6,

    // 11.25° slopes
    TILE_SLOPE_11_UP_RIGHT_0 = 7,
    TILE_SLOPE_11_UP_RIGHT_1 = 8,
    TILE_SLOPE_11_UP_RIGHT_2 = 9,
    TILE_SLOPE_11_UP_RIGHT_3 = 10,

    TILE_SLOPE_11_UP_LEFT_0  = 11,
    TILE_SLOPE_11_UP_LEFT_1  = 12,
    TILE_SLOPE_11_UP_LEFT_2  = 13,
    TILE_SLOPE_11_UP_LEFT_3  = 14
};

struct SlopeInfo {
    int rise;       // total rise (always 8 pixels for now)
    int horizontal_amount;        // number of tiles horizontally in a slope group (1, 2, 4)
    int index;      // segment index within horizontal slope group
    bool up_right;  // direction, true if up-right, false if up-left
};

class player_movement{

    public:

        int debug_value_1;
        
        int debug_value_2;
        
        int debug_value_3;
        
        int debug_value_4;

        player_movement();

        void on_spawn();
        void set_collision_data(const std::vector<std::vector<int>>* data);
        bool is_tile_solid(int tile_x, int tile_y) const;
        void horizontal_collision();
        void vertical_collision();
        bn::fixed handle_movement(); // returns how much the player has moved to the right

        bn::fixed x;
        bn::fixed y;

        bool facing_left;
        bool is_moving_horizontally;
        bool on_slope;

        bn::fixed x_velocity;
        const bn::fixed acceleration = 0.2;
        const bn::fixed turnaround_acceleration_multiplier = 3;
        const bn::fixed max_speed = 1.8;
        const bn::fixed friction = 0.95;

        bn::fixed y_velocity;
        bool on_ground = false;

        const bn::fixed ground_y = 90;
        const bn::fixed gravity = 0.1;
        const bn::fixed fall_gravity = 0.2;
        const bn::fixed jump_strength = 4.1;
        const bn::fixed max_falling_speed = 3;
        const bn::fixed speed = 1;
        //TODO: add max fall speed

        const int tile_width = 8; // move to level
        const int tile_height = 8; // move to level

        // Player collision box settings
        const int half_width = 7;
        const int half_height = 14;
        const int collision_box_offset_x = 0;
        const int collision_box_offset_y = -1;

        const std::vector<std::vector<int>>* collision_data;

        // Slope handling----------------------------------------

        bool is_slope(int tile_x, int tile_y) const ;
        SlopeInfo get_slope_info(int tile) const ;
        bn::fixed get_slope_floor_y(int tile_x, int tile_y, bn::fixed world_x) const;
};


