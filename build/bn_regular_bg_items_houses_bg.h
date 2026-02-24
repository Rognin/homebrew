#ifndef BN_REGULAR_BG_ITEMS_HOUSES_BG_H
#define BN_REGULAR_BG_ITEMS_HOUSES_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(houses_bg_bn_gfx)

//======================================================================
//
//	houses_bg_bn_gfx, 256x256@8, 
//	+ palette 32 entries, not compressed
//	+ 403 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 64 + 25792 + 2048 = 27904
//
//	Time-stamp: 2025-11-26, 22:21:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HOUSES_BG_BN_GFX_H
#define GRIT_HOUSES_BG_BN_GFX_H

#define houses_bg_bn_gfxTilesLen 25792
extern const bn::tile houses_bg_bn_gfxTiles[806];

#define houses_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell houses_bg_bn_gfxMap[1024];

#define houses_bg_bn_gfxPalLen 64
extern const bn::color houses_bg_bn_gfxPal[32];

#endif // GRIT_HOUSES_BG_BN_GFX_H

//}}BLOCK(houses_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item houses_bg(
            regular_bg_tiles_item(span<const tile>(houses_bg_bn_gfxTiles, 806), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(houses_bg_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(houses_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

