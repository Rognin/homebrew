#ifndef BN_REGULAR_BG_ITEMS_MOUNTAINS_BG_H
#define BN_REGULAR_BG_ITEMS_MOUNTAINS_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(mountains_bg_bn_gfx)

//======================================================================
//
//	mountains_bg_bn_gfx, 512x256@4, 
//	+ palette 16 entries, not compressed
//	+ 689 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 32 + 22048 + 4096 = 26176
//
//	Time-stamp: 2025-11-26, 22:21:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MOUNTAINS_BG_BN_GFX_H
#define GRIT_MOUNTAINS_BG_BN_GFX_H

#define mountains_bg_bn_gfxTilesLen 22048
extern const bn::tile mountains_bg_bn_gfxTiles[689];

#define mountains_bg_bn_gfxMapLen 4096
extern const bn::regular_bg_map_cell mountains_bg_bn_gfxMap[2048];

#define mountains_bg_bn_gfxPalLen 32
extern const bn::color mountains_bg_bn_gfxPal[16];

#endif // GRIT_MOUNTAINS_BG_BN_GFX_H

//}}BLOCK(mountains_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item mountains_bg(
            regular_bg_tiles_item(span<const tile>(mountains_bg_bn_gfxTiles, 689), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(mountains_bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(mountains_bg_bn_gfxMap[0], size(64, 32), compression_type::NONE, 1, false));
}

#endif

