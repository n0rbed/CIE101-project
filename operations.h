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

class operrotate :public operation
{
public:
	operrotate(game* r_pGame);
	virtual void Act();
	
};




class operResizeUp :public operation
{
public:
	operResizeUp(game* r_pGame);
	virtual void Act();
};


class operResizeDown :public operation
{
public:
	operResizeDown(game* r_pGame);
	virtual void Act();
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




class operAddCar :public operation
{
public:
	operAddCar(game* r_pGame);
	virtual void Act();
};





class operAddIceCream :public operation
{
public:
	operAddIceCream(game* r_pGame);
	virtual void Act();
};





class operAddRocket :public operation
{
public:
	operAddRocket(game* r_pGame);
	virtual void Act();
};





class operAddTree:public operation
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




class operAddDumbell :public operation
{
public:
	operAddDumbell(game* r_pGame);
	virtual void Act();
};
