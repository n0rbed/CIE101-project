#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <cstdlib> 
#include <iostream>
using namespace std;


grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}


void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);

	//Draw ALL shapes
	color colors[3] = { RED, BLUE, BLACK };
	for (int i = 0; i < shapeCount; i++)
	{
		if (pGame->getLevel() < 3)
		{
			config.penColor = colors[i];
			config.fillColor = colors[i];
		}
		if (shapeList[i]) {
			shapeList[i]->update_color();
			shapeList[i]->draw();	//draw each shape
		}
		config.penColor = BLACK;
		config.fillColor = BLACK;

	}

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}


void grid::deleteActiveShape()
{
	clearGridArea();
	window* pWind = pGame->getWind();

	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i])
			shapeList[i]->draw();	//draw each shape
	if (activeShape) {
		delete activeShape;
		activeShape = nullptr;
	}

}


void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	if (!(newShape->check_boundary())) { return false; }

	// 2- check shape count doesn't exceed maximum count
	if (shapeCount + 1 == MaxShapeCount) { return false; }

	// checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::generate_level(int level_n)
{
	srand(time(0));
	int n_shapes = (2 * level_n) - 1;
	int area_width = (width/2)/10;
	int area_height = height/10;
	
	int x_range = area_width - (area_width / 12) + 1;
	int x_lb = area_width / 12;

	int y_range = area_height - 1;
	int y_lb = uprLeft.y/10;


	shape* new_shape = nullptr;
	for (int i = 0; i < n_shapes; i++) {
		int shape_t = (rand() % (6)) + 1;

		int ref_x = ((rand() % (x_range)) + x_lb) * 10;
		int ref_y = ((rand() % (y_range)) + y_lb) * 10;
		point ref = { ref_x, ref_y };

		int n_rotations = (rand() % (4)) + 1;
		// from negative 1 to 1, where negative means size down
		int n_size = (rand() % (1+1+1)) - 1;

		switch (shape_t) {
			case 1:
				new_shape = new iceCream(pGame, ref);
				break;
			case 2:
				new_shape = new car(pGame, ref);
				break;
			case 3:
				new_shape = new rocket(pGame, ref);
				break;
			case 4:
				new_shape = new mosque(pGame, ref);
				break;
			case 5:
				new_shape = new tree(pGame, ref);
				break;
			case 6:
				new_shape = new dumbbell(pGame, ref);
				break;

		}

		for (int j = 0; j < n_rotations; j++) {
			new_shape->rotate();
		}

		if (n_size == 1)
		{
			new_shape->resizeup();
		}
		else if (n_size == -1)
		{
			new_shape->resizedown();
		}


		if (!addShape(new_shape))
		{
			clearGridArea();
			delete new_shape;
			new_shape = nullptr;
			i--;
		}
	}
}

void grid::del_list()
{
	for (int i = 0; i < shapeCount; i++)
	{
		if (shapeList[i])
		{
			delete shapeList[i];
		}
		shapeList[i] = nullptr;
	}
}

shape** grid::get_list()
{
	return shapeList;
}

int grid::get_count() const
{
	return shapeCount;
}

point grid::get_uprLeft() const
{
	return uprLeft;
}

int grid::get_h() const
{
	return height;
}

int grid::get_w() const
{
	return width;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}



shape* grid::getactiveshape() const
{
	return activeShape;
}

bool grid::refPoints_checker(int* list, int* list2, int name)
{
	if (name == 2 || name == 6) {
		if (list[0] != list2[0] || list[1] != list2[1]) {
			return false;
		}
		if (list[2] == list2[2] && list[3] == list2[3] && list[4] == list2[4] && list[5] == list2[5]) {
			return true;
		}
		if (list[2] == list2[4] && list[3] == list2[5] && list[4] == list2[2] && list[5] == list2[3]) {
			return true;
		}
		return false;
	}

	else if (name == 1 || name == 4 || name == 3) {

		for (int i = 0; i < 4; i++) {
			if (list[i] && list2[i]) {
				if (list[i] != list2[i]) {
					return false;
				}
			}
		}

	}

	else
		for (int i = 0; i < 6; i++) {
			if (list[i] && list2[i]) {
				if (list[i] != list2[i]) {
					return false;
				}
			}
		}
	return true;
}


bool grid::nextLevel() {
	for (int i = 0; i < MaxShapeCount; i++) {
		if (shapeList[i] != nullptr) {
			return false;
		}
	}
	return true;
}


void grid::matchingDetection()
{
	
	
	for (int i = 0; i < MaxShapeCount; i++)
	{
		
		if (activeShape && shapeList[i]) {
			if (activeShape->get_name() == shapeList[i]->get_name()) {
				if (refPoints_checker(activeShape->get_ref_list(), shapeList[i]->get_ref_list(),activeShape->get_name())) {
					delete shapeList[i];
					shapeList[i] = nullptr;
					deleteActiveShape();
					pGame->setScore(pGame->getScore()+3);
					if (nextLevel()) {
						pGame->setLevel(pGame->getLevel() + 1);
					}
					draw();
				}
			}
		}

	}
	if (pGame->getScore() > 0) {
		pGame->setScore(pGame->getScore() - 1);
	}
}
