# README
## File structure
- .cpp files in src/
- .h files in include/
- Graphics in graphics/
## Important
- Each image file requires a json with additional information to function

## Project Requirements

<details>
<summary><strong>⬜ Large animated player (meta)sprite</strong></summary>

- 🟩 Source image format, production tools, constraints  
- 🟩 Toolchain for generating native format  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project (how to play and control animated sprites)

</details>

<details>
<summary><strong>⬜ Player Controller</strong></summary>

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
<summary><strong>⬜ Scrolling tiled background</strong></summary>

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
<summary><strong>⬜ Collisions</strong></summary>

- 🟩 Player / Background  
- 🟩 Player / Object  
- ⬜ Sprite collision rectangles in animated sprites  
- 🟩 Reacting to collisions in code  

</details>

<details>
<summary><strong>⬜ Enemy</strong></summary>

- 🟩 Simple behavior (move left/right)  
- ⬜ Bonus: melee and/or ranged attack  

</details>

<details>
<summary><strong>⬜ Items</strong></summary>

- 🟩 Walk over item/object to pick up  
- ⬜ Bonus: animation or effect for pick-up  
- ⬜ Bonus: inventory system  

</details>

<details>
<summary><strong>⬜ Damage / Health</strong></summary>

- 🟩 Player loses health upon touching enemy  
- 🟩 Player dies when health ≤ 0  
- 🟩 Enemy gets hit upon attack  
- 🟩 Visual effect (e.g., flash white)  
- 🟩 Bonus: enemy dies and scoring / reward system  

</details>

<details>
<summary><strong>⬜ Music</strong></summary>

- 🟩 Source music format, production tools, constraints  
- 🟩 Toolchain for producing, exporting, and converting music  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project  
- 🟩 Play music  
- ⬜ Control music during gameplay  

</details>

<details>
<summary><strong>⬜ Sound FX</strong></summary>

- 🟩 Source sound format, production tools, constraints  
- 🟩 Toolchain for producing, exporting, and converting sound effects  
- 🟩 Target format (e.g., converter output)  
- 🟩 Code integration into buildable project  
- 🟩 Play sound effects  
- 🟩 Control sound effects  

</details>
