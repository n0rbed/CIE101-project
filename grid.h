#pragma once
#include "CompositeShapes.h"

class game;

class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int height, width;
	point uprLeft;	//upper left point of the grid

	//ShapeList should hold the RANDOMLY generated shapes
	shape* shapeList[MaxShapeCount];	//2D array of shape pointers

	shape* activeShape;	//The shape that the user works on to match to the ranom shapes

	int shapeCount;		//current number of shapes in the list
	game* pGame;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	void deleteActiveShape();
	void clearGridArea() const;
	void setActiveShape(shape* actShape);

	bool addShape(shape* newShape);
	void generate_level(int level_n);

	// bounds
	point get_uprLeft() const;
	int get_h() const;
	int get_w() const;
	
	bool nextLevel();
	void matchingDetection();
	bool refPoints_checker(int* list, int* list2, int name);
	shape* grid::getactiveshape() const;
};

