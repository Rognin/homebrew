
@{{BLOCK(heart_bn_gfx)

@=======================================================================
@
@	heart_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2026-02-25, 15:11:28
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global heart_bn_gfxTiles		@ 32 unsigned chars
	.hidden heart_bn_gfxTiles
heart_bn_gfxTiles:
	.word 0x01100990,0x11999799,0x11999979,0x11999999,0x11999999,0x01999990,0x00199900,0x00019000

	.section .rodata
	.align	2
	.global heart_bn_gfxPal		@ 32 unsigned chars
	.hidden heart_bn_gfxPal
heart_bn_gfxPal:
	.hword 0x0000,0x0010,0x0200,0x0210,0x4000,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(heart_bn_gfx)
