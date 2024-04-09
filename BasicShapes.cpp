#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}



////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here


triangle::triangle(game* r_pGame, point ref, int r_base, int r_height):shape(r_pGame, ref)
{
	base = r_base;
	height = r_height;
}
triangle::triangle(game* r_pGame, point ref, int r_base, int r_height, point *input_top):shape(r_pGame, ref)
{
	base = r_base;
	height = r_height;
	ptop = input_top;
}
void triangle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);

	point upperLeft, upperRight, top_point;
	upperLeft.x = RefPoint.x - (base / 2);
	upperLeft.y = RefPoint.y - (height / 2);

	upperRight.x = RefPoint.x + (base / 2);
	upperRight.y = RefPoint.y - (height / 2);

	// if the user does not input a point for the top_point's location,
	// assume its in the middle
	if (ptop == nullptr) {
		top_point.x = RefPoint.x;
		top_point.y = RefPoint.y + (height / 2);

		pW->DrawTriangle(upperLeft.x, upperLeft.y, upperRight.x, upperRight.y, top_point.x, top_point.y);
	}
	else
	{
		pW->DrawTriangle(upperLeft.x, upperLeft.y, upperRight.x, upperRight.y, ptop->x, ptop->y);
	}
}

