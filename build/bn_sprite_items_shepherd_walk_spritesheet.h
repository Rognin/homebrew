#ifndef BN_SPRITE_ITEMS_SHEPHERD_WALK_SPRITESHEET_H
#define BN_SPRITE_ITEMS_SHEPHERD_WALK_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(shepherd_walk_spritesheet_bn_gfx)

//======================================================================
//
//	shepherd_walk_spritesheet_bn_gfx, 32x384@8, 
//	+ palette 48 entries, not compressed
//	+ 192 tiles Metatiled by 4x4 not compressed
//	Total size: 96 + 12288 = 12384
//
//	Time-stamp: 2026-02-24, 15:36:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SHEPHERD_WALK_SPRITESHEET_BN_GFX_H
#define GRIT_SHEPHERD_WALK_SPRITESHEET_BN_GFX_H

#define shepherd_walk_spritesheet_bn_gfxTilesLen 12288
extern const bn::tile shepherd_walk_spritesheet_bn_gfxTiles[384];

#define shepherd_walk_spritesheet_bn_gfxPalLen 96
extern const bn::color shepherd_walk_spritesheet_bn_gfxPal[48];

#endif // GRIT_SHEPHERD_WALK_SPRITESHEET_BN_GFX_H

//}}BLOCK(shepherd_walk_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item shepherd_walk_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(shepherd_walk_spritesheet_bn_gfxTiles, 384), bpp_mode::BPP_8, compression_type::NONE, 12), 
            sprite_palette_item(span<const color>(shepherd_walk_spritesheet_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

