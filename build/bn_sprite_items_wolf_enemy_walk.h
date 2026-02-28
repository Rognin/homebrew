#ifndef BN_SPRITE_ITEMS_WOLF_ENEMY_WALK_H
#define BN_SPRITE_ITEMS_WOLF_ENEMY_WALK_H

#include "bn_sprite_item.h"

//{{BLOCK(wolf_enemy_walk_bn_gfx)

//======================================================================
//
//	wolf_enemy_walk_bn_gfx, 32x128@8, 
//	+ palette 48 entries, not compressed
//	+ 64 tiles Metatiled by 4x4 not compressed
//	Total size: 96 + 4096 = 4192
//
//	Time-stamp: 2026-02-27, 23:09:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WOLF_ENEMY_WALK_BN_GFX_H
#define GRIT_WOLF_ENEMY_WALK_BN_GFX_H

#define wolf_enemy_walk_bn_gfxTilesLen 4096
extern const bn::tile wolf_enemy_walk_bn_gfxTiles[128];

#define wolf_enemy_walk_bn_gfxPalLen 96
extern const bn::color wolf_enemy_walk_bn_gfxPal[48];

#endif // GRIT_WOLF_ENEMY_WALK_BN_GFX_H

//}}BLOCK(wolf_enemy_walk_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item wolf_enemy_walk(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(wolf_enemy_walk_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(wolf_enemy_walk_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

