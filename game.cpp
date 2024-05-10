#include "game.h"
#include "gameConfig.h"
#include <iostream>
using namespace std;



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	// randomize shapes here
	shapesGrid->generate_level(*level);
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
	delete score;
	delete lives;
	delete level;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(int clickedItem)
{

	string items[14] = { "ITM_ICECREAM", "ITM_CAR", "ITM_ROCKET","ITM_TREE", "ITM_MOSQUE","ITM_DUMBBELL", "ITM_INCREASE", "ITM_DECREASE", "ITM_ROTATE", "ITM_REFRESH", "ITM_HINT", "ITM_DELETE", "ITM_SELECTLEVEL", "ITM_SAVE" };
	if (clickedItem <= 13) {
		printMessage(items[clickedItem]);
	}
	else
		printMessage("PLAYER INFORMATION"); // should be fixed, currently this 
	// always gets printed when arrow keys are presseed
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_ROTATE:
		op = new operrotate(this);
			break;
	case ITM_INCREASE:
		op = new operResizeUp(this);
			break;
	case ITM_DECREASE:
		op = new operResizeDown(this);
			break;
	case ITM_CAR:
		op= new operAddCar(this);
		break;
	case ITM_ICECREAM:
		op = new operAddIceCream(this);
		break;
	case ITM_ROCKET:
		op = new operAddRocket(this);
		break;
	case ITM_TREE:
		op = new operAddTree(this);
		break;
	case ITM_MOSQUE:
		op = new operAddMosque(this);
		break;
	case ITM_DUMBBELL:
		op = new operAddDumbell(this);
		break;
	case ITM_DELETE:
		shapesGrid->deleteActiveShape();
		break;
	case (ARROW_DOWN+ITM_CNT):
		 op = new operMove(this, ARROW_DOWN);
		break;
	case (ARROW_LEFT+ITM_CNT) :
		op = new operMove(this, ARROW_LEFT);
		break;
	case (ARROW_RIGHT+ITM_CNT):
		op = new operMove(this, ARROW_RIGHT);
		break;
	case (ARROW_UP+ITM_CNT):
		op = new operMove(this, ARROW_UP);
		break;
	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), "You clicked on "+ msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}




int* game::getScore() const
{
	return score;
}

int* game::getLives() const
{
	return lives;
}

int* game::getLevel() const
{
	return level;
}



////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	char cKeyData;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem=ITM_CNT;
	do
	{
		//printMessage("Ready...");
		//1- Get user click

		pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		keytype key_input = pWind->GetKeyPress(cKeyData);

		operation* op = nullptr;

		if (key_input == ARROW) {
			 switch (cKeyData)
			 {
			 case 2:
				 op = createRequiredOperation(ARROW_DOWN+ITM_CNT);
				 break;
			 case 4:
				 op = createRequiredOperation(ARROW_LEFT+ITM_CNT);
				 break;
			 case 6:
				 op = createRequiredOperation(ARROW_RIGHT+ITM_CNT);
				 break;
			 case 8:
				 op = createRequiredOperation(ARROW_UP+ITM_CNT);
				 break;
			 }

		}



		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem=gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			op = createRequiredOperation(clickedItem);
		}	
		if (op) {
			op->Act();
			shapesGrid->draw();
		}

		// generate random shapes 
	} while (clickedItem!=ITM_EXIT);
}