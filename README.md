# README
## Notes
- The code (found in src/ and include/) has comments, if you want to know what a certain part does there's *usually* a comment nearby.
- Not every header in include/ is written by us, everything that starts with "common_" is copied from Butano examples.
## Folder structure
- audio/ contains music + SFX
- build contains files created by Butano when the project is being built
- dmg_audio is empty as we don't have this kind of audio
- graphics/ contains graphics
- include/ contains headers
- level_data/ contains the csv of a level (though not the one currently used in-game)
- src/ contains the code (.cpp files)
- testProject.gba is the ROM
## How to run the project
- If you just want to play the game, launch the ROM (testProject.gba). Tested with mGBA, should work with any GBA emulator
- If you want to build the project yourself, you should first follow a guide on how to build with Butano, then:
When you are ready to build, copy the folders: audio, graphics, include, src. The makefile should be configured by you manually.
The makefile in this repository is from one of our machines, shouldn't work anywhere else.
Later we will update the repository to make it possible to build from a Docker image.
## Features
In the "Project Requirements" section (below) you can find a list of features that were required for the Homebrew elective.
There the features we have are marked in green, the ones we don't are marked in grey.
Here we talk a about some of the features in more detail, as more of a technical overview.
### Sprites, animations, backgrounds
The graphics work as described in Butano documentation here: https://gvaliente.github.io/butano/import.html
### Audio, SFX
The main music track is a .mod file, SFX are small .wav files. Beyond that Butano does all the work
### Level map
The map for the level is created with Tiled. Than it is exported both as an image of the level and as a collision map.
The collision map is then turned into a 2D vector with a script to use in code, while the image of the level is treated as a background layer.
### Player controller and collision
Player controller is created following this guide: http://higherorderfun.com/blog/2012/05/20/the-guide-to-implementing-2d-platformers/comment-page-2/
The levels are tile-based, with slopes being the only exception. Slopes work as described in the guide.
Collision between objects is mostly resolved as aabb to aabb, although sometimes we use circle to circle where the exact hitboxes are not important.

## Project Requirements

<details>
<summary><strong>🟩 Large animated player (meta)sprite</strong></summary>

- 🟩 Source image format, production tools, constraints  
- 🟩 Toolchain for generating native format  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project (how to play and control animated sprites)

</details>

<details>
<summary><strong>🟩 Player Controller</strong></summary>

- 🟩 Minimum: move (walk and/or run) left/right  
- 🟩 Minimum: jump  
- 🟩 Minimum: fall  
- 🟩 Minimum: attack  
- ⬜ Bonus: multiple attacks (melee and/or range)  
- 🟩 Collision detection with background tiles  
- 🟩 Walk on floor / platforms  
- 🟩 Stop at walls  
- 🟩 Slope handling (uneven terrain)  
- 🟩 Input via controller  
- 🟩 Platforms  
- ⬜ Bonus: moving platforms  

</details>

<details>
<summary><strong>🟩 Scrolling tiled background</strong></summary>

- 🟩 Source image format, production tools, constraints  
- 🟩 Toolchain for generating native format  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project  
- 🟩 Render tiled background  
- 🟩 Scroll background  
- ⬜ Animated tiles  
- 🟩 Parallax scrolling layers  
- ⬜ Fake parallax scrolling layers  
- ⬜ Horizontal sections scrolling at different speeds  

</details>

<details>
<summary><strong>🟩 Collisions</strong></summary>

- 🟩 Player / Background  
- 🟩 Player / Object  
- ⬜ Sprite collision rectangles in animated sprites  
- 🟩 Reacting to collisions in code  

</details>

<details>
<summary><strong>🟩 Enemy</strong></summary>

- 🟩 Simple behavior (move left/right)  
- ⬜ Bonus: melee and/or ranged attack  

</details>

<details>
<summary><strong>🟩 Items</strong></summary>

- 🟩 Walk over item/object to pick up  
- ⬜ Bonus: animation or effect for pick-up  
- ⬜ Bonus: inventory system  

</details>

<details>
<summary><strong>🟩 Damage / Health</strong></summary>

- 🟩 Player loses health upon touching enemy  
- 🟩 Player dies when health ≤ 0  
- 🟩 Enemy gets hit upon attack  
- 🟩 Visual effect (e.g., flash white)  
- 🟩 Bonus: enemy dies and scoring / reward system  

</details>

<details>
<summary><strong>🟩 Music</strong></summary>

- 🟩 Source music format, production tools, constraints  
- 🟩 Toolchain for producing, exporting, and converting music  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project  
- 🟩 Play music  
- ⬜ Control music during gameplay  

</details>

<details>
<summary><strong>🟩 Sound FX</strong></summary>

- 🟩 Source sound format, production tools, constraints  
- 🟩 Toolchain for producing, exporting, and converting sound effects  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project  
- 🟩 Play sound effects  
- 🟩 Control sound effects  

</details>
