//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	int hght, wdth;	//height and width of the recangle
	
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	point getRefPoint()const;


	int getheight() const
	{
		return hght;
	}


	int getwidth() const
	{
		return wdth;
	}

};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle:public shape
{
	//Add data memebrs for class circle
	int rad;
public:	
	circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;


	 int getradius() const
	{
		return rad;
	}





	point getRefPoint()const;


};


class triangle:public shape
{
	int base, height;
	double current_angle;
	point upperLeft, upperRight, top_point;

public:
	triangle(game* r_pGame, point ref, int r_base, int r_height);
	void update_tpoints();

	virtual void draw() const override;
	virtual void rotate() override;
	virtual void resizeup() override;
	virtual void resizedown() override;
	virtual void move(arrows direction) override;
	point getRefPoint()const;
	double get_curAngle() const;


	int getbase() const
	{
		return base;
	}
	
	int gethght() const
	{
		return height;
	}



};
