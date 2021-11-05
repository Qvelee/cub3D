# cub3D

### Description

This project is implementation of simple ray-casting engine.
 
### Build

 Run `make` in project root directory. This will create `cub3d` executable. Program supports 2 mods:

  1. Test mode with simple textures and sprites. To use just run `make';
  2. "Play" mode with several sprites and textures. To use run `make bonus`.
 
 To remove all files created by program run `make fclean`, or `make clean` to remove all except executable.
 
### Usage

Program requires 1 argument - map file. For example, for test mode run `cub3d maps/basic_map.cub`.

Use `W`, `A`, `S`, `D` to move across the map and mouse or numpad arrows to move camera.
`Esc` to exit.
