# 💣 Bomberman Game

A modern, pixel-art recreation of the **classic Bomberman arcade game**, built using **C++ and the SFML (Simple and Fast Multimedia Library)**. Players dive into a grid-based arena, placing bombs strategically to blow up bricks and outsmart enemies — all while dodging their own explosions. It's a retro blast packed with modern polish!


---

## 🎮 Game Features

- 🧨 **Strategic Bombing**: Place bombs that explode in a cross-shape after 3 seconds, destroying nearby bricks and enemies.
- 👾 **Enemy AI**: Dodge 5 moving enemies that bounce off obstacles and track across the grid.
- 🧱 **Dynamic Arena**: Mix of unbreakable blocks and 30 randomly placed breakable bricks.
- 💾 **High Score System**: Earn points for bricks and enemies, and store your top 3 scores in a file!
- 🎵 **Immersive Audio**: Background music, bomb explosions, and death sounds to keep your adrenaline high.
- 📺 **Screen Transitions**: Includes Start Menu, Game Over screen, and High Score display.

---

## 🕹️ Controls

| Action         | Key            |
|----------------|----------------|
| Move           | W, A, S, D      |
| Place Bomb     | Spacebar        |
| Exit Game      | Escape          |
| Menu Navigation| Mouse           |
| Back to Menu   | Backspace       |

---

## 🧠 Gameplay Mechanics

- **Arena**: 768x768 pixel grid divided into 64x64 tiles.
- **Bomb Logic**:
  - Explodes after 3 seconds.
  - 1-second explosion animation.
  - Cross-range up to 2 tiles.
- **Scoring**:
  - +5 points for each brick destroyed.
  - +50 points per enemy killed.
- **Game Over**:
  - Triggered by touching enemies or own explosion.
  - Plays death sound and transitions to Game Over screen.

---

## 🧱 Game Architecture

| Class       | Description                                                                 |
|-------------|-----------------------------------------------------------------------------|
| `Player`    | Manages movement, collision detection, and bomb placement.                  |
| `Enemy`     | Handles 5 autonomous enemies with varied patterns.                          |
| `Bomb`      | Controls timing, placement, and animation of bomb and explosion.            |
| `Brick`     | Randomly places 30 breakable bricks on the arena.                           |
| `Blocks`    | Fixed unbreakable grid obstacles (36 in total).                             |
| `Screens`   | Start screen, High Score screen, Game Over screen.                          |
| `Buttons`   | Interactive menu buttons with hover effect.                                 |
| `Score`     | Tracks game score and handles `highscore.txt` file I/O.                     |

---

## ⚙️ Requirements

- ✔️ C++ Compiler (e.g. g++)
- ✔️ [SFML Library](https://www.sfml-dev.org/) (Graphics, Audio, System modules)
- ✔️ Texture & Audio Assets (included)
- ✔️ Font: Arial.ttf
- ✔️ `highscore.txt` (auto-created if missing)

---

## 🚀 How to Run

1. **Install SFML** in your development environment.
2. **Clone the repository**:
   ```bash
   git clone https://github.com/Musab-Farooq/Bomberman.git
   cd Bomberman

## Compile and run:
  ```bash
  g++ main.cpp -o bomberman -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
  ./bomberman
  ```

## 📦 One-Click Run

Want to try **without compiling**?

- [**Download the ZIP release**](https://github.com/Musab-Farooq/Bomberman/blob/main/BomberMan.zip)  
- Extract the folder.
- Run the provided `.exe` file inside to launch Bomberman instantly!

---
