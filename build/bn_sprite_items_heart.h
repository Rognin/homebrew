#ifndef BN_SPRITE_ITEMS_HEART_H
#define BN_SPRITE_ITEMS_HEART_H

#include "bn_sprite_item.h"

//{{BLOCK(heart_bn_gfx)

//======================================================================
//
//	heart_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2026-02-25, 15:11:28
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HEART_BN_GFX_H
#define GRIT_HEART_BN_GFX_H

#define heart_bn_gfxTilesLen 32
extern const bn::tile heart_bn_gfxTiles[1];

#define heart_bn_gfxPalLen 32
extern const bn::color heart_bn_gfxPal[16];

#endif // GRIT_HEART_BN_GFX_H

//}}BLOCK(heart_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item heart(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(heart_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(heart_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

