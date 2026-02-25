
@{{BLOCK(debug_attack_sprite_bn_gfx)

@=======================================================================
@
@	debug_attack_sprite_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-02-25, 17:05:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global debug_attack_sprite_bn_gfxTiles		@ 128 unsigned chars
	.hidden debug_attack_sprite_bn_gfxTiles
debug_attack_sprite_bn_gfxTiles:
	.word 0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777
	.word 0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777
	.word 0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777
	.word 0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777

	.section .rodata
	.align	2
	.global debug_attack_sprite_bn_gfxPal		@ 32 unsigned chars
	.hidden debug_attack_sprite_bn_gfxPal
debug_attack_sprite_bn_gfxPal:
	.hword 0x0000,0x0010,0x0200,0x0210,0x4000,0x4010,0x4200,0x6318
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(debug_attack_sprite_bn_gfx)
