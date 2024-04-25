#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddCar::operAddCar(game* r_pGame) :operation(r_pGame)
{
}

void operAddCar::Act()
{
	window* pw = pGame->getWind();

	
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point carShapeRef = { xGrid,yGrid };

	shape* psh = new car(pGame, carShapeRef);

	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}




operAddIceCream::operAddIceCream(game* r_pGame) :operation(r_pGame)
{
}

void operAddIceCream::Act()
{
	window* pw = pGame->getWind();

	
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point iceCreamShapeRef = { xGrid,yGrid };


	shape* psh = new iceCream(pGame, iceCreamShapeRef);
		
	
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}

void operAddRocket::Act()
{
	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	
	point rocketShapeRef = { xGrid,yGrid };

	
	shape* psh = new rocket(pGame, rocketShapeRef);

	
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddTree::operAddTree(game* r_pGame) :operation(r_pGame)
{
}

void operAddTree::Act()
{
	window* pw = pGame->getWind();

	
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	
	point treeShapeRef = { xGrid,yGrid };

	shape* psh = new tree(pGame, treeShapeRef);

	
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



operAddMosque::operAddMosque(game* r_pGame) :operation(r_pGame)
{
}

void operAddMosque::Act()
{
	window* pw = pGame->getWind();

	
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point mosqueShapeRef = { xGrid,yGrid };


	shape* psh = new mosque(pGame, mosqueShapeRef);

	
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddDumbbell::operAddDumbbell(game* r_pGame) :operation(r_pGame)
{
}

void operAddDumbbell::Act()
{
	window* pw = pGame->getWind();


	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	point dumbbellShapeRef = { xGrid,yGrid };


	shape* psh = new dumbbell(pGame, dumbbellShapeRef);


	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
