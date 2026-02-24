#ifndef BN_SPRITE_ITEMS_SHEPHERD_IDLE_H
#define BN_SPRITE_ITEMS_SHEPHERD_IDLE_H

#include "bn_sprite_item.h"

//{{BLOCK(shepherd_idle_bn_gfx)

//======================================================================
//
//	shepherd_idle_bn_gfx, 32x256@8, 
//	+ palette 48 entries, not compressed
//	+ 128 tiles Metatiled by 4x4 not compressed
//	Total size: 96 + 8192 = 8288
//
//	Time-stamp: 2025-11-27, 11:12:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SHEPHERD_IDLE_BN_GFX_H
#define GRIT_SHEPHERD_IDLE_BN_GFX_H

#define shepherd_idle_bn_gfxTilesLen 8192
extern const bn::tile shepherd_idle_bn_gfxTiles[256];

#define shepherd_idle_bn_gfxPalLen 96
extern const bn::color shepherd_idle_bn_gfxPal[48];

#endif // GRIT_SHEPHERD_IDLE_BN_GFX_H

//}}BLOCK(shepherd_idle_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item shepherd_idle(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(shepherd_idle_bn_gfxTiles, 256), bpp_mode::BPP_8, compression_type::NONE, 8), 
            sprite_palette_item(span<const color>(shepherd_idle_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

