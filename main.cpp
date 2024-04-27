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
	triangle rockeT(r_pGame, ref,20, 10);
	rockeT.draw();
	Game.run();
	rockeT.draw();
	rockeT.rotate();
	rockeT.rotate();
	rockeT.draw();

	
	return 0;
}

