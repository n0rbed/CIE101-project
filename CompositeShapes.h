#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;


};



class iceCream :public shape
{
	circle* cream;
	triangle* cone;
public:
	iceCream(game* r_pGame, point ref);
	virtual void draw() const;
};




class car : public shape
{
	circle* left_wheel;
	circle* right_wheel;
	Rect* body;
public:
	car(game* r_pGame, point ref);
	virtual void draw() const;
};



class rocket : public shape 
{
	Rect* body;
	triangle* head;
	triangle* left_wing;
	triangle* right_wing;
public:
	rocket(game* r_pGame, point ref);
	virtual void draw() const;
};


class tree : public shape
{
	Rect* log;
	triangle* leafs;
public:
	tree(game* r_pGame, point ref);
	virtual void draw() const;
};


class mosque : public shape
{
	Rect* base, *left_tower, *right_tower;
	triangle* left_th, *right_th;
	circle* oba;
public:
	mosque(game* r_pGame, point ref);
	virtual void draw() const;
};
