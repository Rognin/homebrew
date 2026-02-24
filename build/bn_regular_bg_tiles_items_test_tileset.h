#ifndef BN_REGULAR_BG_TILES_ITEMS_TEST_TILESET_H
#define BN_REGULAR_BG_TILES_ITEMS_TEST_TILESET_H

#include "bn_regular_bg_tiles_item.h"

//{{BLOCK(test_tileset_bn_gfx)

//======================================================================
//
//	test_tileset_bn_gfx, 32x8@4, 
//	+ 4 tiles not compressed
//	Total size: 128 = 128
//
//	Time-stamp: 2025-12-04, 15:14:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TEST_TILESET_BN_GFX_H
#define GRIT_TEST_TILESET_BN_GFX_H

#define test_tileset_bn_gfxTilesLen 128
extern const bn::tile test_tileset_bn_gfxTiles[4];

#endif // GRIT_TEST_TILESET_BN_GFX_H

//}}BLOCK(test_tileset_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item test_tileset(
            span<const tile>(test_tileset_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE);
}

#endif

