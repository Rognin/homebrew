#ifndef BN_REGULAR_BG_ITEMS_TEST_LEVEL_H
#define BN_REGULAR_BG_ITEMS_TEST_LEVEL_H

#include "bn_regular_bg_item.h"

//{{BLOCK(test_level_bn_gfx)

//======================================================================
//
//	test_level_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 160 + 2048 = 2240
//
//	Time-stamp: 2025-12-04, 15:36:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TEST_LEVEL_BN_GFX_H
#define GRIT_TEST_LEVEL_BN_GFX_H

#define test_level_bn_gfxTilesLen 160
extern const bn::tile test_level_bn_gfxTiles[5];

#define test_level_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell test_level_bn_gfxMap[1024];

#define test_level_bn_gfxPalLen 32
extern const bn::color test_level_bn_gfxPal[16];

#endif // GRIT_TEST_LEVEL_BN_GFX_H

//}}BLOCK(test_level_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item test_level(
            regular_bg_tiles_item(span<const tile>(test_level_bn_gfxTiles, 5), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(test_level_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(test_level_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

