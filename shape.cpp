#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <iostream>;
using namespace std;

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

shape::~shape()
{
	cout << "shape destructor called" << endl;
}


point shape::getRefPoint()
{
	return RefPoint;
}











