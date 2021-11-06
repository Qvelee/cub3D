# cub3D

### Description

This project is implementation of simple ray-casting engine.
 
### Build

 Run `make` in project root directory. This will create `cub3d` executable. Program supports 2 mods:

  1. Basic mode with simple textures and sprites. To use just run `make';
  2. "Play" mode with several sprites and textures. To use run `make bonus`.
 
 To remove all files created by program run `make fclean`, or `make clean` to remove all except executable.
 
### Usage

Program requires 1 argument - map file. For example, for basic mode run `cub3d maps/basic_map.cub`.

Use `W`, `A`, `S`, `D` to move across the map and mouse or numpad arrows to move camera.
`Esc` to exit.


### Basic mode
![ezgif com-gif-maker](https://user-images.githubusercontent.com/36854467/140530507-add7d1f6-7a54-4c4b-9347-3cf077d49d59.gif)

### Bonus mode
![ezgif com-gif-maker(3)](https://user-images.githubusercontent.com/36854467/140532601-8c27d90d-d783-499a-a61c-dfcc3729b5fd.gif)
