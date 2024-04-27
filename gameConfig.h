#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	double sizeup = 2;
	double sizedown=0.5;



	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;
	struct {
		int radius = 30;
		int triangle_height = 60;
	}iceShape;
	struct {
		int body_width = 90, body_height = 45;
		int wheel_radius = 15;
	}carShape;
	struct {
		int bodyHeight = 120;
		int headHeight = 80;
		int bodyWidth = 40;
		int wingBase = 40;

	}rocketShape;
	struct {
		int bodyBase = 50;
		int bodyHeight = 150;
		int leafBase = 120;
		int leafHeight = 100;
	}treeShape;
	struct {
		int base_base = 100;
		int tower_base = 50;
		int base_height = 100;
		int tower_height = 150;
		int headt_height = 50;
		int headt_base = 80;
		int oba_radius = 40;
	}mosqueShape;
	struct {
		int h_Length = 80;
		int h_Height = 20;
		int d_radius = 20;
	}dShape;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here		
	ITM_ICECREAM,
	ITM_CAR,
	ITM_ROCKET,
	ITM_TREE,
	ITM_MOSQUE,
	ITM_DUMBBELL,
	ITM_INCREASE,
	ITM_DECREASE,
	ITM_ROTATE,
	ITM_REFRESH,
	ITM_HINT,
	ITM_DELETE,
	ITM_SELECTLEVEL,
	ITM_SAVE,
	ITM_EXIT,
	ITM_CNT
};



