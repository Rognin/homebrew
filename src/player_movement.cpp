#include "player_movement.h"

player_movement::player_movement(){
    facing_left = false;
    x = 0;
    y = 30;
    is_moving_horizontally = false;
    x_velocity = 0;
    y_velocity = 0;
    on_ground = true;
    on_slope = false;
}

void player_movement::on_spawn(){

}

void player_movement::set_collision_data(const std::vector<std::vector<int>>* data) {
    collision_data = data;
}

bool player_movement::is_tile_solid(int tile_x, int tile_y) const {
    if (!collision_data) return false;
    if (tile_y < 0 || tile_y >= (int)collision_data->size()) return false;
    if (tile_x < 0 || tile_x >= (int)(*collision_data)[0].size()) return false;
    return (*collision_data)[tile_y][tile_x] == 0; // -1 = empty
}

bool player_movement::is_slope(int tile_x, int tile_y) const
{
    if (!collision_data) return false;
    if (tile_y < 0 || tile_y >= (int)collision_data->size()) return false;
    if (tile_x < 0 || tile_x >= (int)(*collision_data)[0].size()) return false;
    int t = (*collision_data)[tile_y][tile_x];
    return (t >= TILE_SLOPE_45_UP_RIGHT && t <= TILE_SLOPE_11_UP_LEFT_3);
}

SlopeInfo player_movement::get_slope_info(int tile) const
{
    // 45°
    if(tile == TILE_SLOPE_45_UP_RIGHT)
        return {8, 1, 0, true};
    if(tile == TILE_SLOPE_45_UP_LEFT)
        return {8, 1, 0, false};

    // 22.5° (2 tiles)
    if(tile >= TILE_SLOPE_22_UP_RIGHT_0 && tile <= TILE_SLOPE_22_UP_RIGHT_1)
        return {8, 2, tile - TILE_SLOPE_22_UP_RIGHT_0, true};

    if(tile >= TILE_SLOPE_22_UP_LEFT_0 && tile <= TILE_SLOPE_22_UP_LEFT_1)
        return {8, 2, tile - TILE_SLOPE_22_UP_LEFT_0, false};

    // 11.25° (4 tiles)
    if(tile >= TILE_SLOPE_11_UP_RIGHT_0 && tile <= TILE_SLOPE_11_UP_RIGHT_3)
        return {8, 4, tile - TILE_SLOPE_11_UP_RIGHT_0, true};

    if(tile >= TILE_SLOPE_11_UP_LEFT_0 && tile <= TILE_SLOPE_11_UP_LEFT_3)
        return {8, 4, tile - TILE_SLOPE_11_UP_LEFT_0, false};

    return {0, 0, 0, false};
}

bn::fixed player_movement::get_slope_floor_y(int tile_x, int tile_y, bn::fixed world_x) const
{
    int tile = (*collision_data)[tile_y][tile_x];
    SlopeInfo s = get_slope_info(tile);

    int tile_world_x = tile_x * tile_width;
    int local_x = (world_x.floor_integer() + collision_box_offset_x + tile_width / 2) - tile_world_x;

    local_x = bn::clamp(local_x, 0, tile_width - 1);

    int slope_x = s.index * tile_width + local_x;
    int height;

    if(s.up_right)
        height = s.rise - 1 - (slope_x * s.rise) / (s.horizontal_amount * tile_width);
    else
        height = (slope_x * s.rise) / (s.horizontal_amount * tile_width);

    return bn::fixed(tile_y * tile_height + height);
}

void player_movement::horizontal_collision() {

    // Get level half sizes in pixels
    int level_half_width  = collision_data ? (*collision_data)[0].size() * tile_width / 2 : 0;
    int level_half_height = collision_data ? collision_data->size() * tile_height / 2 : 0;

    // Get player collision box edges in world coordinates, 0 0 is top left (all in pixels)
    int left   = (x.floor_integer() + level_half_width) - half_width + collision_box_offset_x;
    int right  = (x.floor_integer() + level_half_width) + half_width + collision_box_offset_x;
    int top    = (y.floor_integer() + level_half_height) - half_height - collision_box_offset_y;
    int bottom = (y.floor_integer() + level_half_height) + half_height - collision_box_offset_y;

    // Get coordinate of top and bottom intersecting tiles (in tile units)
    int top_tile    = std::floor(float(top + 1) / tile_height);
    int bottom_tile = std::floor(float(bottom - 1) / tile_height);

    int loop_top = top_tile;
    int loop_bottom = bottom_tile;

    // feet_pixel_x is 7 pixels to the right of left collider edge
    // feet_pixel_y is at the bottom collider edge
    int feet_pixel_x = left + collision_box_offset_x + half_width;
    int feet_pixel_y = bottom;

    // debug_value_1 = left + collision_box_offset_x + half_width;
    // debug_value_2 = bottom;
    // debug_value_3 = float(feet_pixel_x) / tile_width;
    // debug_value_4 = float(feet_pixel_y) / tile_height;

    if(is_slope(std::floor(float(feet_pixel_x) / tile_width), std::floor(float(feet_pixel_y - 1) / tile_height))){
        loop_bottom -= 1;
    }

    if(!on_ground) {
        loop_top += 1;
    }

    if(on_slope){
        // if on slope don't check collision at 1 above ground level to avoid getting stuck on tile behind slope
        loop_bottom -= 2;
    }

    if (x_velocity > 0) { // moving right
        int right_check = right + 1;
        int right_tile_check = std::floor(float(right_check) / tile_width);
        for(int ty = loop_top; ty <= loop_bottom; ty++) {
            if(is_tile_solid(right_tile_check, ty)) {
                int collision_right = right_tile_check * tile_width;
                x = collision_right - half_width - collision_box_offset_x - level_half_width - 1; // push left
                x_velocity = 0;
                break;
            }
        }
    } else if (x_velocity < 0) { // moving left
        int left_check = left - 1;
        int left_tile_check = std::floor(float(left_check) / tile_width);
        for(int ty = loop_top; ty <= loop_bottom; ty++) {
            if(is_tile_solid(left_tile_check, ty)) {
                int collision_left = (left_tile_check + 1) * tile_width;
                x = collision_left + half_width - collision_box_offset_x - level_half_width; // push right
                x_velocity = 0;
                break;
            }
        }
    }
}

void player_movement::vertical_collision() {

    on_ground = false;
    on_slope = false;

    int level_half_width  = collision_data ? (*collision_data)[0].size() * tile_width / 2 : 0;
    int level_half_height = collision_data ? collision_data->size() * tile_height / 2 : 0;

    int left   = (x.floor_integer() + level_half_width) - half_width + collision_box_offset_x;
    int right  = (x.floor_integer() + level_half_width) + half_width + collision_box_offset_x;
    int top    = (y.floor_integer() + level_half_height) - half_height - collision_box_offset_y;
    int bottom = (y.floor_integer() + level_half_height) + half_height - collision_box_offset_y;

    // feet_pixel_x is 7 pixels to the right of left collider edge
    // feet_pixel_y is at the bottom collider edge
    // during vertical movement the collider is 1 pixel inside the ground because
    // we just incremented vertical position but haven't resolved collisions yet
    int feet_pixel_x = left + collision_box_offset_x + half_width;
    int feet_pixel_y = bottom;

    int left_tile   = std::floor(float(left) / tile_width);
    int right_tile  = std::floor(float(right) / tile_width);
    int top_tile    = std::floor(float(top) / tile_height);
    int bottom_tile = std::floor(float(bottom) / tile_height);

    debug_value_1 = feet_pixel_x;
    debug_value_2 = feet_pixel_y;
    debug_value_3 = x.floor_integer();
    debug_value_4 = y.floor_integer();

    // check if on_slope
    if(is_slope(std::floor(float(feet_pixel_x) / tile_width), std::floor(float(feet_pixel_y) / tile_height))){
        on_slope = true;
    } else {
        // Check if inside a slope tile but still on the ground (enter onto the slope)
        if(is_slope(std::floor(float(feet_pixel_x) / tile_width), std::floor(float(feet_pixel_y - 1) / tile_height))){
            on_slope = true;
            feet_pixel_y --; // move feet 1 pixel up to correctly detect that we're inside a slope
        }
    }

    if (y_velocity >= 0) { // falling
        bool collided = false;
        int check_bottom = feet_pixel_y;
        int bottom_tile_check = std::floor(float(check_bottom) / tile_height);

        if(on_slope) {
            int slope_x = std::floor(float(feet_pixel_x) / tile_width);
            int slope_y = std::floor(float(feet_pixel_y) / tile_height);
            SlopeInfo s = get_slope_info((*collision_data)[slope_y][slope_x]);
            int slope_left_hight;
            int slope_right_height;
            if(s.up_right){
                slope_left_hight = s.rise/s.horizontal_amount * s.index;
                slope_right_height = s.rise/s.horizontal_amount * (s.index + 1);
            }else{
                slope_left_hight = s.rise/s.horizontal_amount * (s.horizontal_amount - s.index);
                slope_right_height = s.rise/s.horizontal_amount * (s.horizontal_amount - s.index - 1);
            }
            // debug_value_1 = slope_left_hight;
            // debug_value_2 = slope_right_height;

            int feet_on_slope_x = (feet_pixel_x - (slope_x * tile_width));
            // Calculate expected feet y on slope
            float t = float(feet_on_slope_x) / float(tile_width);
            float expected_feet_y_offset_upwards = slope_left_hight + t * (slope_right_height - slope_left_hight);
            // debug_value_3 = int(expected_feet_y_offset_upwards);
            int collision_bottom = bottom_tile_check * tile_height;
            y = bn::fixed(collision_bottom - half_height + collision_box_offset_y - level_half_height + tile_height - expected_feet_y_offset_upwards);
                y_velocity = 0;
                on_ground = true;
                collided = true;
                return;
        }
        
        for(int tx = left_tile; tx <= right_tile; tx++) {
            if(is_tile_solid(tx, bottom_tile_check)) {
                int collision_bottom = bottom_tile_check * tile_height;
                y = bn::fixed(collision_bottom - half_height + collision_box_offset_y - level_half_height);
                y_velocity = 0;
                on_ground = true;
                collided = true;
                break;
            }
        }

    } else if (y_velocity < 0) { // jumping
        for(int tx = left_tile; tx <= right_tile; tx++) {
            if(is_tile_solid(tx, top_tile)) {
                int collision_top = (top_tile + 1) * tile_height;
                y = collision_top + half_height + collision_box_offset_y - level_half_height;
                y_velocity = 0;
                break;
            }
        }
    }
}

bn::fixed player_movement::handle_movement(){

    // Read inputs

    // Jump
    if(bn::keypad::up_pressed() && on_ground)
    {
        y_velocity = -jump_strength;
        on_ground = false;
    }

    // Cut jump height if up is released
    if(!bn::keypad::up_held() && y_velocity < 0)
    {
        y_velocity /= 2;   // reduces jump height
    }

    // Horizontal movement
    if(bn::keypad::left_held())
    {
        facing_left = true;
        if(x_velocity > 0)
            x_velocity -= acceleration * turnaround_acceleration_multiplier;
        else
            x_velocity -= acceleration;
        is_moving_horizontally = true;
    }
    else if(bn::keypad::right_held())
    {
        facing_left = false;
        if(x_velocity < 0)
            x_velocity += acceleration * turnaround_acceleration_multiplier;
        else
            x_velocity += acceleration;
        is_moving_horizontally = true;
    }
    else
    {
        is_moving_horizontally = false;
        x_velocity *= friction;
    }

    if(x_velocity > max_speed)
        x_velocity = max_speed;
    else if(x_velocity < -max_speed)
        x_velocity = -max_speed;


    // Apply gravity
    if(y_velocity < 0){
        y_velocity += gravity;
    } else {
        y_velocity += fall_gravity;
    }

    if(y_velocity > max_falling_speed){
        y_velocity = max_falling_speed;
    }

    x += x_velocity;
    horizontal_collision();

    y += y_velocity;
    vertical_collision();

    // check harcoded ground collision
    // if(y >= ground_y)
    // {
    //     y = ground_y;
    //     y_velocity = 0;
    //     on_ground = true;
    // }

    if(is_moving_horizontally){
        return x_velocity;
    } else {
        return 0;
    }
}