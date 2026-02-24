#ifndef BN_SPRITE_ITEMS_CLOAKED_IDLE_SPRITESHEET_H
#define BN_SPRITE_ITEMS_CLOAKED_IDLE_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(cloaked_idle_spritesheet_bn_gfx)

//======================================================================
//
//	cloaked_idle_spritesheet_bn_gfx, 32x384@4, 
//	+ palette 16 entries, not compressed
//	+ 192 tiles Metatiled by 4x8 not compressed
//	Total size: 32 + 6144 = 6176
//
//	Time-stamp: 2025-11-26, 22:21:13
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOAKED_IDLE_SPRITESHEET_BN_GFX_H
#define GRIT_CLOAKED_IDLE_SPRITESHEET_BN_GFX_H

#define cloaked_idle_spritesheet_bn_gfxTilesLen 6144
extern const bn::tile cloaked_idle_spritesheet_bn_gfxTiles[192];

#define cloaked_idle_spritesheet_bn_gfxPalLen 32
extern const bn::color cloaked_idle_spritesheet_bn_gfxPal[16];

#endif // GRIT_CLOAKED_IDLE_SPRITESHEET_BN_GFX_H

//}}BLOCK(cloaked_idle_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cloaked_idle_spritesheet(sprite_shape_size(sprite_shape::TALL, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(cloaked_idle_spritesheet_bn_gfxTiles, 192), bpp_mode::BPP_4, compression_type::NONE, 6), 
            sprite_palette_item(span<const color>(cloaked_idle_spritesheet_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

