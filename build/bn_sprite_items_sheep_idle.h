#ifndef BN_SPRITE_ITEMS_SHEEP_IDLE_H
#define BN_SPRITE_ITEMS_SHEEP_IDLE_H

#include "bn_sprite_item.h"

//{{BLOCK(sheep_idle_bn_gfx)

//======================================================================
//
//	sheep_idle_bn_gfx, 16x80@8, 
//	+ palette 48 entries, not compressed
//	+ 20 tiles Metatiled by 2x2 not compressed
//	Total size: 96 + 1280 = 1376
//
//	Time-stamp: 2025-11-27, 11:13:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SHEEP_IDLE_BN_GFX_H
#define GRIT_SHEEP_IDLE_BN_GFX_H

#define sheep_idle_bn_gfxTilesLen 1280
extern const bn::tile sheep_idle_bn_gfxTiles[40];

#define sheep_idle_bn_gfxPalLen 96
extern const bn::color sheep_idle_bn_gfxPal[48];

#endif // GRIT_SHEEP_IDLE_BN_GFX_H

//}}BLOCK(sheep_idle_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item sheep_idle(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(sheep_idle_bn_gfxTiles, 40), bpp_mode::BPP_8, compression_type::NONE, 5), 
            sprite_palette_item(span<const color>(sheep_idle_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

