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
	virtual bool check_boundary() override;


};



class iceCream :public shape
{
	circle* cream;
	triangle* cone;
	point triangle_ref;
	point circle_ref;
	

public:
	iceCream(game* r_pGame, point ref);
	~iceCream();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	virtual bool check_boundary() override;

};




class car : public shape
{
	circle* left_wheel;
	circle* right_wheel;
	Rect* body;
	point body_ref, left_wheel_ref, right_wheel_ref;
	
	
public:
	car(game* r_pGame, point ref);
	~car();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	virtual bool check_boundary() override;

};



class rocket : public shape 
{
	Rect* body;
	triangle* head;
	triangle* left_wing;
	triangle* right_wing;
	point body_ref, head_ref, left_wing_ref, right_wing_ref;
public:
	rocket(game* r_pGame, point ref);
	~rocket();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	virtual bool check_boundary() override;
};


class tree : public shape
{
	Rect* log;
	triangle* leafs;
	point log_ref, leaf_ref;
public:
	tree(game* r_pGame, point ref);
	~tree();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	virtual bool check_boundary() override;
};


class mosque : public shape
{
	Rect* base, *left_tower, *right_tower;
	triangle* left_th, *right_th;
	circle* oba;
	point base_ref, left_tower_ref, right_tower_ref, left_th_ref, right_th_ref, oba_ref;
public:
	mosque(game* r_pGame, point ref);
	~mosque();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	virtual bool check_boundary() override;
};

class dumbbell : public shape
{
	Rect* handle; 
	circle* left_w;
	circle* right_w;
	point handle_ref, left_w_ref, right_w_ref;

public:
	dumbbell(game* r_pGame, point ref);
	~dumbbell();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	virtual bool check_boundary() override;
};
