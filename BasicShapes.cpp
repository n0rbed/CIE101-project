#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;


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

void Rect::rotate()
{
	// Swap width and height to reflect the rotation 
	int temp = wdth;
	wdth = hght;
	hght = temp;

}

void Rect::resizeup()
{
	wdth = wdth * config.sizeup;
	hght = hght * config.sizeup;

}


void Rect::resizedown()
{

	wdth = wdth * config.sizedown;
	hght = hght * config.sizedown;

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






void circle::rotate()
{

}

void circle::resizeup()
{
	rad = rad * config.sizeup;
}


void circle::resizedown()
{
	rad = rad * config.sizedown;

}




////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here
void triangle::update_tpoints()
{
	if (current_angle == 0) {
		upperLeft.x = RefPoint.x - (base / 2);
		upperLeft.y = RefPoint.y - (height / 2);

		upperRight.x = RefPoint.x + (base / 2);
		upperRight.y = RefPoint.y - (height / 2);

		top_point.x = RefPoint.x;
		top_point.y = RefPoint.y + (height / 2);
	}
	else {
		for (int i = current_angle; i > 0; i -= 90) {
			current_angle -= 90;
			rotate();
		}
	}
}

triangle::triangle(game* r_pGame, point ref, int r_base, int r_height):shape(r_pGame, ref)
{
	current_angle = 0;
	base = r_base;
	height = r_height;
	
	update_tpoints();
}

void triangle::draw() const
{



	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);


	pW->DrawTriangle(upperLeft.x, upperLeft.y, upperRight.x, upperRight.y, top_point.x, top_point.y);

}

	void triangle::rotate()
	{
		// Update rotation angle to rotate by 90 degrees

		current_angle += 90;
		// Convert angle to radians
		double angle_rad = current_angle * (M_PI / 180.0);

		// Calculate trigonometric functions
		double cosTheta = cos(angle_rad);
		double sinTheta = sin(angle_rad);

		// Define triangle vertices
		point vertices[3] = { {RefPoint.x - (base / 2),RefPoint.y - (height/2)},

							  {RefPoint.x + (base / 2), RefPoint.y - (height/2)},

							  {RefPoint.x, RefPoint.y + (height/2)} };

		// Rotate each vertex around the reference point
		for (int i = 0; i < 3; ++i) {

			double newX = cosTheta * (vertices[i].x - RefPoint.x) - sinTheta * (vertices[i].y - RefPoint.y) + RefPoint.x;
			double newY = sinTheta * (vertices[i].x - RefPoint.x) + cosTheta * (vertices[i].y - RefPoint.y) + RefPoint.y;

			// Update vertex coordinates
			vertices[i].x = newX;
			vertices[i].y = newY;
		}

		// Redraw the triangle with the new vertices
		window* pW = pGame->getWind();
		pW->SetPen(config.penColor, config.penWidth);
		pW->SetBrush(config.fillColor);

		upperLeft.x = vertices[0].x;
		upperLeft.y = vertices[0].y;

		upperRight.x = vertices[1].x;
		upperRight.y = vertices[1].y;

		top_point.x = vertices[2].x;
		top_point.y = vertices[2].y;

	}

	



	void triangle::resizeup()
	{
		base = base * config.sizeup;
		height = height * config.sizeup;
		update_tpoints();
	}

	void triangle::resizedown()
	{
		base = base * config.sizedown;
		height = height * config.sizedown;
		update_tpoints();
	}


	point triangle::getRefPoint() const
	{
		return RefPoint;
	}

	double triangle::get_curAngle() const
	{
		return current_angle;
	}

	point circle::getRefPoint() const
	{
		return RefPoint;
	}
	
	point Rect::getRefPoint() const
	{
		return RefPoint;
	}







