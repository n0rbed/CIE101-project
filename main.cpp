#include "game.h"


int main()
{

	//Create an object of controller
	/**
	game Game;
	Game.run();
	**/

	game Game;
	game* r_pGame = &Game;
	point ref = { 400,400 };
	dumbbell rockeT(r_pGame, ref);
	rockeT.draw();
	Game.run();
	rockeT.draw();

	
	return 0;
}

