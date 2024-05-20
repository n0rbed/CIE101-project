#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed
	int score = 0;
	int lives = 5;
	int level = 3;
	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void selectLevelBar(string msg) const;
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid

	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(int clickedItem);

	void createPlayerInformation();
	int getScore() const;
	int getLives() const;
	int getLevel() const;
	void setScore(int s);
	void setLives(int l);
	void setLevel(int l);

	

	void run();	//start the game

};

