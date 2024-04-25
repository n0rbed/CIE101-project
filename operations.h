#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};


class operAddIceCream :public operation
{
public:
	operAddIceCream(game* r_pGame);
	virtual void Act();
};


class operAddCar :public operation
{
public:
	operAddCar(game* r_pGame);
	virtual void Act();
};

class operAddRocket :public operation
{
public:
	operAddRocket(game* r_pGame);
	virtual void Act();
};


class operAddTree :public operation
{
public:
	operAddTree(game* r_pGame);
	virtual void Act();
};


class operAddMosque :public operation
{
public:
	operAddMosque(game* r_pGame);
	virtual void Act();
};

class operAddDumbbell :public operation
{
public:
	operAddDumbbell(game* r_pGame);
	virtual void Act();
};

