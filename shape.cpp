#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <iostream>;
#include <fstream>
using namespace std;

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
	for (int i = 0; i < 6; i++) {
		ref_list[i] = nullptr;
	}
	name = 0;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

shape::~shape()
{
	for (int i = 0; i < 6; i++) {
		ref_list[i] = nullptr;
	}
	
}



point shape::getRefPoint()
{
	return RefPoint;
}



int shape::get_name() const
{
	return name;
}


int* shape::get_ref_list() const
{
	return ref_list[0];
}

void shape::save(ofstream& OutF)
{

	OutF << name << "\t" << RefPoint.x << "\t" << RefPoint.y << "\t"  << rotationCount << "\t" << sizeCount  << endl;

}


void shape::update_color()
{
	fillColor = config.fillColor;
	borderColor = config.penColor;
}



void shape::rotate()
{
	rotationCount++;
}

void shape::resizeup()
{
	sizeCount++;
}

void shape::resizedown()
{
	sizeCount--;
}



