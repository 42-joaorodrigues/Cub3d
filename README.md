# cub3D

![42 Badge](https://img.shields.io/badge/42-cub3D-brightgreen)
![C Badge](https://img.shields.io/badge/Language-C-blue)
![Graphics Badge](https://img.shields.io/badge/Graphics-Ray--casting-orange)

> A 3D maze explorer inspired by Wolfenstein 3D, built from scratch using ray-casting techniques.

<!-- Screenshot placeholder: Add gameplay screenshot here -->
![Gameplay Screenshot](https://via.placeholder.com/800x450/1a1a1a/ffffff?text=Gameplay+Screenshot)

---

## Overview

**cub3D** recreates the magic of early 3D games by rendering a first-person 3D perspective from a 2D map. Navigate through mazes, explore textured environments, and experience how classic games like Wolfenstein 3D brought 3D graphics to life.

**Perfect for:**
- Anyone curious about retro 3D gaming
- Developers interested in graphics programming
- Students learning computer graphics fundamentals

---

## Quick Start

### Prerequisites
- Linux system with X11
- GCC compiler
- Make

### Installation & Running

```bash
# Clone and navigate
git clone https://github.com/42-joaorodrigues/Cub3d.git
cd Cub3d

# Compile
make

# Run the game
./cub3D map/valid/map.cub
```

### Controls
| Key | Action |
|-----|--------|
| `W` `A` `S` `D` | Move forward, left, backward, right |
| `←` `→` | Rotate camera left/right |
| `ESC` | Exit game |

---

## Features

<!-- Screenshot placeholder: Add textured walls showcase here -->
![Textured Walls](https://via.placeholder.com/400x300/2a2a2a/ffffff?text=Textured+Walls)

### Core Gameplay
- **Real-time 3D rendering** using ray-casting algorithms
- **Custom wall textures** for each direction (North, South, East, West)
- **Configurable colors** for floors and ceilings
- **Smooth movement** with collision detection
- **Fluid camera rotation** for exploration

<!-- Screenshot placeholder: Add map configuration example here -->
![Map Configuration](https://via.placeholder.com/400x300/2a2a2a/ffffff?text=Map+Configuration)

### Technical Highlights
- DDA algorithm for efficient wall detection
- Texture mapping with perspective correction
- Event-driven input system
- Memory-safe implementation
- Optimized for smooth 60fps performance

---

## 🗺️ Map Configuration

Maps are defined in `.cub` files with texture paths, colors, and layout:

```
NO ./asset/north_wall.xpm    # North wall texture
SO ./asset/south_wall.xpm    # South wall texture
WE ./asset/west_wall.xpm     # West wall texture
EA ./asset/east_wall.xpm     # East wall texture

F 220,100,0                  # Floor color (RGB)
C 135,206,235                # Ceiling color (RGB)

        1111111111111
        1000000000001
        1000000000001
11111111100000N000001
10000000000000000001
10000000000000000001
11111111111111111111
```

**Map Rules:**
- `1` = Wall
- `0` = Empty space
- `N/S/E/W` = Player start position (facing North/South/East/West)
- Map must be surrounded by walls

---

## Project Structure

```
cub3d/
├── src/
│   ├── main/          # Initialization and game loop
│   ├── input/         # Map parsing and validation
│   ├── graphic/       # Ray-casting and rendering
│   └── keyhook/       # Input handling
├── inc/               # Header files
├── libft/             # Custom utility library
├── mlx/               # MiniLibX graphics library
├── map/               # Sample maps
│   ├── valid/         # Playable maps
│   └── error/         # Test cases for error handling
└── asset/             # Texture files (.xpm)
```

---

## Team

Collaborative development by:
- **[@ghjoaorodrigues](https://github.com/ghjoaorodrigues)** - Map parsing & validation
- **[@fabiosilva24](https://github.com/fabiosilva24)** - Ray-casting engine & graphics

---

## Make Commands

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove all build files
make re     # Rebuild from scratch
```

---

## What We Learned

- Ray-casting mathematics and 3D projection
- Graphics pipeline and rendering optimization
- File parsing with robust error handling
- Real-time event-driven programming
- Memory management in C
- Team collaboration and code modularity

---

## License

This project is licensed under the [MIT License](./LICENSE).

---

*A 42 School project exploring computer graphics fundamentals and ray-casting techniques.*
