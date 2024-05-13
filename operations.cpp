#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <iostream>
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}



operrotate:: operrotate(game*r_pGame):operation(r_pGame)
{

}


void operrotate::Act()
{
	grid* pGrid = pGame->getGrid();

	shape* activeShape = pGrid->getactiveshape();

	if (activeShape) 
	{
		activeShape->rotate();
		pGrid->draw();

	}
}



operResizeUp::operResizeUp(game* r_pGame) :operation(r_pGame)
{

}


void operResizeUp::Act()
{
	grid* pGrid = pGame->getGrid();

	shape* activeShape = pGrid->getactiveshape();

	if (activeShape)
	{
		activeShape->resizeup();
		pGrid->draw();
	}
}




operResizeDown::operResizeDown(game* r_pGame) :operation(r_pGame)
{

}


void operResizeDown::Act()
{
	grid* pGrid = pGame->getGrid();

	shape* activeShape = pGrid->getactiveshape();

	if (activeShape) 
	{
		activeShape->resizedown();
		pGrid->draw();
	}
}





operMove::operMove(game* r_pGame, arrows direction) :operation(r_pGame)
{
	this->direction = direction;
}

void operMove::Act() {
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getactiveshape();
	
	if (activeShape) {
		activeShape->move(direction);
		pGrid->draw();
	}
	

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

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point carShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new car(pGame, carShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}












operAddIceCream::operAddIceCream(game* r_pGame) :operation(r_pGame)
{
}



void operAddIceCream::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point iceCreamShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new iceCream(pGame, iceCreamShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}



void operAddRocket::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point rocketShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new rocket(pGame, rocketShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}




operAddTree::operAddTree(game* r_pGame) :operation(r_pGame)
{
}


void operAddTree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	cout << "tree x: " << xGrid << endl;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	cout << "tree y: " << yGrid << endl;

	//take the aligned point as the sign shape ref point
	point treeShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new tree(pGame, treeShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddMosque::operAddMosque(game* r_pGame) :operation(r_pGame)
{
}


void operAddMosque::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point mosqueShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new mosque(pGame, mosqueShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



operAddDumbell::operAddDumbell(game* r_pGame) :operation(r_pGame)
{
}


void operAddDumbell::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point dumbellShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new dumbbell(pGame, dumbellShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



