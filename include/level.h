#pragma once

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_music_item.h"
#include "bn_assert.h"

#include "bn_string.h"
#include <string>
#include <vector>

#include "csv_loader.h"

#include "bn_regular_bg_items_level_512_512_slopes.h"

class Level
{
public:
    struct SpawnPoint
    {
        int x = 0;
        int y = 0;
    };

    Level(
        // const std::string& collision_file_name,
        // const bn::music_item& music_item,
        SpawnPoint player_spawn
    );

    // Load everything needed for the level
    void load();

    // Unload level
    void unload();

    const std::vector<std::vector<int>>& get_collision_data() const {
        return collision_data;
    }

    SpawnPoint get_player_spawn() const {
        return _player_spawn;
    }

    bn::regular_bg_ptr level_image;
    std::vector<std::vector<int>> collision_data;

private:
    // Name of collision CSV file
    std::string _collision_file_name;

    // Collision data vector
    

    // Music
    // const bn::music_item& _music_item;

    // Player starting position
    SpawnPoint _player_spawn;

    // Helper: read CSV collision file
    std::vector<std::vector<int>> _read_collision_csv(const std::string& filename);
};
