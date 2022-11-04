<p align="center"><img src="https://game.42sp.org.br/static/assets/achievements/so_longm.png"> </p>
<p align="center"><b>succeeded with 101%*</b></p>
<p align="center"><img align="middle" src="https://github.com/mmuriloj/so_long/blob/155907273c937e587dd06440df251b80b3081394/so_long.gif" width=65% height=65% /></p>


### SO_LONG
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

### Mandatory goal
Your project must comply with the following rules:
- You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Your program has to take as parameter a map description file ending with the .ber extension.

### Game
- The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
- The W, A, S, and D keys must be used to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- You have to use a 2D view (top-down or profile).

### Graphic management
Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

### Map
The map has to be constructed with 3 components: walls, collectibles, and free
space.
- The map can be composed of only these 5 characters:
- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for a map exit,
- P for the player’s starting position
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- If the map contains a duplicates characters (exit/start), you should display an error message.
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map, as long as it respects the above rules.
- If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.

### Makefile and use

In order to compile the game, one must type `make` one the root folder. To run the game,  `./so_long <path-to-mapfile.ber>` 

Example
```bash
>> make
>> ./so_long maps/valid/map7.ber
```

### MinilibX
MinilibX is a graphic engine created by 42. It can be found [here](https://github.com/42Paris/minilibx-linux)
with some useful documentation.
1. [42docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
2. [Aurelien Brabant's documentation](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
