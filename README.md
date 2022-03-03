## Description

This project is inspired by the world-famous Wolfenstein 3D game. 

It's a graphic design project the objective of which is to create a dynamic view inside a maze using raycasting method and [miniLibX](https://github.com/42Paris/minilibx-linux).

![image](https://user-images.githubusercontent.com/75207011/156568548-3a586371-00c5-4e76-a7d8-2640e799a75b.png)

## Map
The program takes as a first argument a scene description file with the .cub extension
- The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.
- North texture
- South texture
- West texture
- East texture
- Floor color: R,G,B colors in range [0,255]: 0, 255, 255
- Ceilling color: R,G,B colors in range [0,255]: 0, 255, 255

Example with a minimalist .cub scene:

![image](https://user-images.githubusercontent.com/75207011/156571193-f8240308-822a-4ba4-a6b2-aad628b8cc94.png)


## Keys
**W, A, S, D** to move the point of view through the maze

**Left/Right arrows** to rotate camera

**ESC** must close the window and quit the program cleanly

## Running on MacOS
```
https://github.com/MeSugar/cub3d.git
cd cub3d
make
./cub3D map.cub 
```

Use ./cub3D --save map.cub to save starting view BMP screenshot
