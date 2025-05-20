# Bomberman Game

A classic arcade-inspired Bomberman game developed using C++ and the SFML (Simple and Fast Multimedia Library) framework. In this game, players navigate a grid-based arena, strategically placing bombs to destroy breakable bricks and defeat enemies while avoiding collisions with enemies and their own explosions. The game features a start menu, high score system, and immersive audio-visual elements.

Features
Gameplay: Control a player character to place bombs that explode after a delay, destroying nearby bricks and enemies. Avoid enemies moving across the grid and survive your own bomb explosions to score points.
Graphics: Pixel-art style visuals with sprites for the player, enemies, breakable bricks, unbreakable blocks, bombs, and explosions, rendered using SFML.
Audio: Background music, sound effects for player movement, bomb explosions, enemy kills, and player death enhance the gaming experience.

Mechanics:
Player Movement: Move in a grid-based arena (768x768 pixels) with 64x64 pixel tiles, avoiding unbreakable blocks and breakable bricks.
Bombs: Place bombs that explode after 3 seconds, clearing bricks and enemies within a cross-shaped radius (up to 2 tiles away).
Enemies: Five enemies move horizontally or vertically, bouncing off arena boundaries and obstacles.
Scoring: Earn 5 points per brick destroyed and 50 points per enemy killed. High scores are saved to a file and displayed on the high score screen.
Screens: Includes a start screen with Start, High Score, and Exit buttons, a game over screen, and a high score screen showing the top three scores.

Controls:
Arrow Keys (W, A, S, D): Move the player up, left, down, or right in 64-pixel increments, restricted by obstacles.
Spacebar: Place a bomb at the player’s current position.
Backspace: Return to the start screen during gameplay.
Mouse: Interact with menu buttons (Start, High Score, Exit, Back).
Escape: Exit the game.
Obstacles: 30 breakable bricks and 36 unbreakable blocks are placed in a grid pattern, with bricks randomly positioned to avoid specific coordinates.
Game Over: Triggered by collision with enemies or bomb explosions, followed by a death sound and game over screen before exiting.

Technical Details
Classes:
Player: Manages player movement, bomb placement, and collision detection.
Bomb: Handles bomb placement, explosion timing, and animation (3-second delay, 1-second explosion).
Enemy: Controls five enemies with randomized starting positions and movement patterns.
Brick: Manages 30 breakable bricks with random placement, avoiding overlaps with enemies.
Blocks: Places 36 unbreakable blocks in a fixed grid pattern.
Screens: Handles start, high score, and game over screens with interactive buttons.
Buttons: Implements clickable buttons with hover effects for menu navigation.
score and Highscore: Tracks and displays the player’s score and saves/displays top scores in a file (highscore.txt).
SFML Integration: Utilizes SFML for rendering sprites, handling events, playing audio, and managing the game window.
File Management: High scores are persistently stored in highscore.txt and displayed in descending order.
This project showcases object-oriented programming, collision detection, game state management, file I/O, and SFML-based graphics and audio handling. Ideal for learning game development or enjoying a retro-style Bomberman experience!

Requirements
SFML library
C++ compiler
Texture files (Textures/ folder: player.png, playerRR.png, playerLR.png, playerU.png, playerD.png, enemy.png, breakblocks.png, blocks.png, bomb.png, explosion.png, background.png, startscreen.png, highscore.png, gameover.png, button.png, highscorebutton.png, exitbutton.png, backbutton.png)
Audio files (Music/ folder: bgmusic.mp3, death.wav; Sound/ folder: Bounce1.mp3, kill.wav)
Font file (Fonts/ folder: arial.ttf)
High score file (highscore.txt)

How to Run
Ensure SFML is installed and configured in your development environment.
Place all texture, audio, and font files in the respective Textures/, Music/, Sound/, and Fonts/ directories relative to the executable.
Compile and run main.cpp to start the game.
Navigate the start menu using the mouse, play the game with keyboard controls, and view high scores after gameplay.
Enjoy blasting your way through the Bomberman arena!

NOTE: To play game without setting up SFML in your system just download the zip file and hit exe file to play game
