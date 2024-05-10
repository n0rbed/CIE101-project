#include "toolbar.h"
#include "game.h"
#include <iostream>
using namespace std;
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_ICECREAM] = "images\\toolbarItems\\ice_cream.jpg";
	toolbarItemImages[ITM_CAR] = "images\\toolbarItems\\car.jpg";
	toolbarItemImages[ITM_ROCKET] = "images\\toolbarItems\\rocket.jpg";
	toolbarItemImages[ITM_TREE] = "images\\toolbarItems\\tree.jpg";
	toolbarItemImages[ITM_MOSQUE] = "images\\toolbarItems\\mosque.jpg";
	toolbarItemImages[ITM_DUMBBELL] = "images\\toolbarItems\\dumbbell.jpg";
	toolbarItemImages[ITM_INCREASE] = "images\\toolbarItems\\increase.jpg";
	toolbarItemImages[ITM_DECREASE] = "images\\toolbarItems\\decrease.jpg";
	toolbarItemImages[ITM_ROTATE] = "images\\toolbarItems\\rotate.jpg";
	toolbarItemImages[ITM_REFRESH] = "images\\toolbarItems\\refresh.jpg";
	toolbarItemImages[ITM_HINT] = "images\\toolbarItems\\hint.jpg";
	toolbarItemImages[ITM_DELETE] = "images\\toolbarItems\\delete.jpg";
	toolbarItemImages[ITM_SELECTLEVEL] = "images\\toolbarItems\\select_level.jpg";
	toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\save.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);

	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);


	int* pScore = pG->getScore();
	auto score = std::to_string(*pScore);  //convert int to string

	int* pLives = pG->getLives();
	auto lives = std::to_string(*pLives);  //convert int to string

	int* pLevel = pG->getLevel();
	auto level = std::to_string(*pLevel);  //convert int to string


	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->DrawString((ITM_CNT + 0.2) * config.toolbarItemWidth, 0, lives + " LIVES");
	pWind->DrawString((ITM_CNT + 0.2) * config.toolbarItemWidth, 20, "SCORE = " + score);
	pWind->DrawString((ITM_CNT + 0.2) * config.toolbarItemWidth, 40, "LEVEL = " + level);
	
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}

