#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main() {
	Game* game = new Game();
	game->loop();
	return 0;
}

/*
Note:
to drive, walk IN FRONT of a tower and press space (if your in the tower it will not work)
press space again to leave the tower.
press backspace to spawn an enemy on the track (currently they just sit at the start of the track (all the way to the far right))
move with the arrow keys

Assets by Always Sometimes Monsters
Assets by Kenney Vleugels (Kenney or www.kenney.n1)
Donate:   http://support.kenney.nl
Request:  http://request.kenney.nl
Follow on Twitter for updates: @KenneyWings

for the Map, delimit the map with 0's, 1 for area where the player can walk and place turrets, 3 if theres a tower there maybe, 8 for where the ennemy can walk, t for the target of the monsters
still need to work on other keys for shops ect. for example, 2 is probably going to be for the town area
*/