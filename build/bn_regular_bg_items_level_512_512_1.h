#ifndef BN_REGULAR_BG_ITEMS_LEVEL_512_512_1_H
#define BN_REGULAR_BG_ITEMS_LEVEL_512_512_1_H

#include "bn_regular_bg_item.h"

//{{BLOCK(level_512_512_1_bn_gfx)

//======================================================================
//
//	level_512_512_1_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 160 + 8192 = 8384
//
//	Time-stamp: 2025-12-10, 13:32:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVEL_512_512_1_BN_GFX_H
#define GRIT_LEVEL_512_512_1_BN_GFX_H

#define level_512_512_1_bn_gfxTilesLen 160
extern const bn::tile level_512_512_1_bn_gfxTiles[5];

#define level_512_512_1_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell level_512_512_1_bn_gfxMap[4096];

#define level_512_512_1_bn_gfxPalLen 32
extern const bn::color level_512_512_1_bn_gfxPal[16];

#endif // GRIT_LEVEL_512_512_1_BN_GFX_H

//}}BLOCK(level_512_512_1_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item level_512_512_1(
            regular_bg_tiles_item(span<const tile>(level_512_512_1_bn_gfxTiles, 5), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(level_512_512_1_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(level_512_512_1_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

