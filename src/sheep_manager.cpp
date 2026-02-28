#include "sheep_manager.h"

sheep_manager::sheep_manager(bn::camera_ptr& camera) : camera(camera),
    text_generator(common::variable_8x16_sprite_font)
{
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::RIGHT);

    text_generator.generate(
        112,   // x (top-right, screen space)
        -72,   // y
        "0",
        text_sprites
    );
}

// Update sheep positions and check for collection
void sheep_manager::update(bn::fixed player_x, bn::fixed player_y) {
    for (int i = sheep_list.size() - 1; i >= 0; --i) {
        sheep_list[i].update();

        bn::fixed dx = sheep_list[i].get_x() - player_x;
        bn::fixed dy = sheep_list[i].get_y() - player_y;

        if (std::abs(dx.integer()) < sheep_pickup_radius && std::abs(dy.integer()) < sheep_pickup_radius) {

            for(size_t j = 0; j < spawn_points.size(); j++) {
                if (spawn_points[j].x == sheep_list[i].get_x() && spawn_points[j].y == sheep_list[i].get_y()) {
                    spawn_points[j].occupied = false;
                    break;
                }
            }

            on_sheep_collected(sheep_list[i]);

            sheep_list.erase(sheep_list.begin() + i);

            collected_count++;
            update_counter();

            spawn_one_sheep(); // Spawn replacement, so the number of sheep to collect doesn't decrease
        }
    }
}

void sheep_manager::update_counter() {
    
    text_sprites = {}; // Clear previous sprites
    text_generator.generate(
        112,
        -72,
        bn::to_string<8>(collected_count),
        text_sprites
    );
}

// Spawns a sheep at a random free spawn point
void sheep_manager::spawn_one_sheep() {
    int spawn_position_index = get_random_free_spawn_point_index();
    if(spawn_position_index == -1) {
        return; // No free spawn points
    }

    spawn_point& spawn_position = spawn_points[spawn_position_index];
    spawn_position.occupied = true;
    sheep_list.push_back(sheep(spawn_position.x, spawn_position.y, camera));
}

// Spawns a sheep at the given position
void sheep_manager::spawn_sheep_at(bn::fixed x, bn::fixed y) {
    sheep_list.push_back(sheep(x, y, camera));
}

void sheep_manager::on_sheep_collected(sheep collected_sheep) {

    bn::sound_items::collect.play();
    // Mark the spawn point as free again
    for (spawn_point& cur_spawn_point : spawn_points) {
        if (cur_spawn_point.x == collected_sheep.get_x() && cur_spawn_point.y == collected_sheep.get_y()) {
            cur_spawn_point.occupied = false;
            break;
        }
    }
}

// Returns the index of a random free spawn point, or -1 if there are no free spawn points
int sheep_manager::get_random_free_spawn_point_index() {
    std::vector<int> free_indices;
    for (size_t i = 0; i < spawn_points.size(); i++) {
        if (!spawn_points[i].occupied) {
            free_indices.push_back(i);
        }
    }

    if (free_indices.empty()) {
        return -1; // No free spawn points
    }

    int random_index = free_indices[std::rand() % free_indices.size()];
    return random_index;
}

void sheep_manager::spawn_initial_sheep() {
    for (int i = 0; i < initial_sheep_count; i++) {
        spawn_one_sheep();
    }
}

// Clears all sheep and respawns the initial sheep
void sheep_manager::reset() {
    sheep_list.clear();
    for (spawn_point& sp : spawn_points) {
        sp.occupied = false;
    }
    collected_count = 0;
    update_counter();

    spawn_initial_sheep();
}