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
	~Sign();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;



};



class iceCream :public shape
{
	circle* cream;
	triangle* cone;
	

public:
	iceCream(game* r_pGame, point ref);
	~iceCream();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;

};




class car : public shape
{
	circle* left_wheel;
	circle* right_wheel;
	Rect* body;
	
	
public:
	car(game* r_pGame, point ref);
	~car();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
};



class rocket : public shape 
{
	Rect* body;
	triangle* head;
	triangle* left_wing;
	triangle* right_wing;
public:
	rocket(game* r_pGame, point ref);
	~rocket();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
};


class tree : public shape
{
	Rect* log;
	triangle* leafs;
public:
	tree(game* r_pGame, point ref);
	~tree();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
};


class mosque : public shape
{
	Rect* base, *left_tower, *right_tower;
	triangle* left_th, *right_th;
	circle* oba;
public:
	mosque(game* r_pGame, point ref);
	~mosque();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
};

class dumbbell : public shape
{
	Rect* handle; 
	circle* left_w;
	circle* right_w;
public:
	dumbbell(game* r_pGame, point ref);
	~dumbbell();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
};
