#include "CompositeShapes.h"
#include "gameConfig.h"
#include <iostream>
using namespace std;
////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
	
}

Sign::~Sign()
{
	delete base;
	delete top;
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}



void Sign::resizeup()
{
	base->resizeup();
	top->resizeup();
}

void Sign::rotate() {

	double cos90 = 0;
	double sin90 = 1;

	point nref;
	nref.x = (base->getRefPoint().x - top->getRefPoint().x) * cos90 - (base->getRefPoint().y - top->getRefPoint().y) * sin90 + top->getRefPoint().x;
	nref.y = (base->getRefPoint().y - top->getRefPoint().y) * cos90 + (base->getRefPoint().x - top->getRefPoint().x) * sin90 + top->getRefPoint().y;

	base->setRefPoint(nref);

	base->rotate();
	top->rotate();

}

void Sign::resizedown()
{
	base->resizedown();
	top->resizedown();
}

void Sign::move(arrows direction)
{
	base->move(direction);
	top->move(direction);

	RefPoint = top->getRefPoint();
}

bool Sign::check_boundary()
{
	if (base->check_boundary() && top->check_boundary())
	{
		return true;
	}
	return false;
}

////////////////////////////////////////////////////  class ice cream  ///////////////////////////////////////
iceCream::iceCream(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	int nothing = 1;
	circle_ref = ref;
	double triangle_offset = config.iceShape.radius * 1.2;

	point triangleref = { ref.x, ref.y + triangle_offset};
	triangle_ref = triangleref;
	cream = new circle(pGame, circle_ref, config.iceShape.radius);
	cone = new triangle(pGame, triangle_ref, 2 * config.iceShape.radius, config.iceShape.triangle_height);
	ref_list[0] = &triangle_ref.x;
	ref_list[1] = &triangle_ref.y;
	ref_list[2] = &circle_ref.x;
	ref_list[3] = &circle_ref.y;
	
	
	
	name = 1;
	
}

iceCream::~iceCream()
{
	delete cream;
	delete cone;
}

void iceCream::draw() const
{
	cream->draw();
	cone->draw();
}


void iceCream::rotate() 
{
	rotationCount++;

	double cos90 = 0;
	double sin90 = 1;

	
	triangle_ref.x = (cone->getRefPoint().x - cream->getRefPoint().x) * cos90 - (cone->getRefPoint().y - cream->getRefPoint().y) * sin90 + cream->getRefPoint().x;
	triangle_ref.y = (cone->getRefPoint().y - cream->getRefPoint().y) * cos90 + (cone->getRefPoint().x - cream->getRefPoint().x) * sin90 + cream->getRefPoint().y;


	cone->setRefPoint(triangle_ref);

	cream->rotate();
	cone->rotate();
	

}


void iceCream::resizeup()
{
	sizeCount++;

	point cone_ref = cone->getRefPoint();
	point cone_newRef = { (cone_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (cone_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };

	cone->setRefPoint(cone_newRef);
	cream->resizeup();
	cone->resizeup();

	if (!check_boundary())
	{
		cone->setRefPoint(cone_ref);
		cream->resizedown();
		cone->resizedown();

		return;
	}

	triangle_ref = cone_newRef;
	
}

void iceCream::resizedown()
{
	sizeCount--;

	point cone_ref = cone->getRefPoint();
	point cone_newRef = { (cone_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (cone_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	cone->setRefPoint(cone_newRef);
	cream->resizedown();
	cone->resizedown();

	if (!check_boundary())
	{
		cone->setRefPoint(cone_ref);
		cream->resizeup();
		cone->resizeup();

		return;
	}

	triangle_ref = cone_newRef;
}

void iceCream::move(arrows direction)
{
	point place_holder_cone = cone->getRefPoint();
	point place_holder_cream = cream->getRefPoint();

	cream->move(direction);
	cone->move(direction);

	if (!check_boundary())
	{
		cone->setRefPoint(place_holder_cone);
		cream->setRefPoint(place_holder_cream);
		return;
	}


	RefPoint = cream->getRefPoint();
	triangle_ref = cone->getRefPoint();
	circle_ref = RefPoint;
}

bool iceCream::check_boundary()
{
	if (cream->check_boundary() && cone->check_boundary())
	{
		return true;
	}
	return false;
}



////////////////////////////////////////////////////  class car  ///////////////////////////////////////
car::car(game* r_pGame, point ref) : shape(r_pGame, ref)
{

	body_ref = ref;

	left_wheel_ref = { ref.x - (config.carShape.body_width/2) + config.carShape.wheel_radius,
	(ref.y + (config.carShape.body_height/3) + config.carShape.wheel_radius) };

	right_wheel_ref = { ref.x + (config.carShape.body_width/2) - config.carShape.wheel_radius,
	ref.y + (config.carShape.body_height/3) + config.carShape.wheel_radius };

	left_wheel = new circle(pGame, left_wheel_ref, config.carShape.wheel_radius);
	right_wheel = new circle(pGame, right_wheel_ref, config.carShape.wheel_radius);
	body = new Rect(pGame, body_ref, config.carShape.body_height, config.carShape.body_width);

	name = 2;
	ref_list[0] = &body_ref.x;
	ref_list[1] = &body_ref.y;
	ref_list[2] = &left_wheel_ref.x;
	ref_list[3] = &left_wheel_ref.y;
	ref_list[4] = &right_wheel_ref.x;
	ref_list[5] = &right_wheel_ref.y;
}

car::~car()
{
	delete left_wheel;
	delete right_wheel;
	delete body;
}

void car::draw() const
{
	left_wheel->draw();
	right_wheel->draw();
	body->draw();
}


void car::rotate()
{
	rotationCount++;

	double cos90 = 0;
	double sin90 = 1;

	point p1, p2;
	p1.x = (left_wheel->getRefPoint().x - body->getRefPoint().x) * cos90 - (left_wheel->getRefPoint().y - body->getRefPoint().y) * sin90 + body->getRefPoint().x;
	p1.y = (left_wheel->getRefPoint().y - body->getRefPoint().y) * cos90 + (left_wheel->getRefPoint().x - body->getRefPoint().x) * sin90 + body->getRefPoint().y;

	p2.x = (right_wheel->getRefPoint().x - body->getRefPoint().x) * cos90 - (right_wheel->getRefPoint().y - body->getRefPoint().y) * sin90 + body->getRefPoint().x;
	p2.y = (right_wheel->getRefPoint().y - body->getRefPoint().y) * cos90 + (right_wheel->getRefPoint().x - body->getRefPoint().x) * sin90 + body->getRefPoint().y;


	left_wheel_ref = p1;
	right_wheel_ref = p2;
	left_wheel->setRefPoint(left_wheel_ref);
	right_wheel->setRefPoint(right_wheel_ref);

	body->rotate();
	left_wheel->draw();
	right_wheel->draw();
	

}



void car::resizeup()
{
	sizeCount++;

	point rw_ref = right_wheel->getRefPoint();
	point lw_ref = left_wheel->getRefPoint();


	point rw_newRef = { (rw_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (rw_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point lw_newRef = { (lw_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (lw_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };


	left_wheel->setRefPoint(rw_newRef);
	right_wheel->setRefPoint(lw_newRef);

	left_wheel->resizeup();
	right_wheel->resizeup();
	body->resizeup();

	if (!check_boundary())
	{
		left_wheel->resizedown();
		right_wheel->resizedown();
		body->resizedown();

		left_wheel->setRefPoint(rw_ref);
		right_wheel->setRefPoint(lw_ref);
		return;
	}

	left_wheel_ref = lw_newRef;
	right_wheel_ref = rw_newRef;

}



void car::resizedown()
{
	sizeCount--;

	point rw_ref = right_wheel->getRefPoint();
	point lw_ref = left_wheel->getRefPoint();

	point rw_newRef = { (rw_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (rw_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };
	point lw_newRef = { (lw_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (lw_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	left_wheel->setRefPoint(rw_newRef);
	right_wheel->setRefPoint(lw_newRef);

	left_wheel->resizedown();
	right_wheel->resizedown();
	body->resizedown();

	if (!check_boundary())
	{
		left_wheel->resizeup();
		right_wheel->resizeup();
		body->resizeup();

		left_wheel->setRefPoint(rw_ref);
		right_wheel->setRefPoint(lw_ref);
		return;
	}

	left_wheel_ref = lw_newRef;
	right_wheel_ref = rw_newRef;
}

void car::move(arrows direction)
{
	left_wheel->move(direction);
	right_wheel->move(direction);
	body->move(direction);


	if (!check_boundary())
	{
		left_wheel->setRefPoint(left_wheel_ref);
		right_wheel->setRefPoint(right_wheel_ref);
		body->setRefPoint(RefPoint);
		return;
	}


	RefPoint = body->getRefPoint();
	body_ref = RefPoint;
	right_wheel_ref = right_wheel->getRefPoint();
	left_wheel_ref = left_wheel->getRefPoint();
}


bool car::check_boundary()
{
	if (body->check_boundary() && left_wheel->check_boundary()
	&& right_wheel->check_boundary())
	{
		return true;
	}
	return false;
}





////////////////////////////////////////////////////  class rocket  ///////////////////////////////////////
rocket::rocket(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	body_ref = ref;
	head_ref = { ref.x, ref.y - (config.rocketShape.bodyHeight / 2) - (config.rocketShape.headHeight / 2) };

	point left_w_ref = { ref.x - (config.rocketShape.bodyWidth / 2) - (config.rocketShape.wingBase / 2),
		ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.bodyWidth / 1.9)};
	left_wing_ref = left_w_ref;

	//point left_wing_top = { ref.x - (config.rocketShape.bodyWidth / 2),
	//	ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.wingBase) };

	point right_w_ref = { ref.x + (config.rocketShape.bodyWidth / 2) + (config.rocketShape.wingBase / 2),
		ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.wingBase / 1.9)};
	right_wing_ref = right_w_ref;

	//point right_wing_top = { ref.x + (config.rocketShape.bodyWidth / 2),
	//	ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.wingBase) };

	body = new Rect(r_pGame, body_ref, config.rocketShape.bodyHeight, config.rocketShape.bodyWidth);
	head = new triangle(r_pGame, head_ref, config.rocketShape.bodyWidth, (-1)*config.rocketShape.headHeight);
	left_wing = new triangle(r_pGame, left_wing_ref, config.rocketShape.bodyWidth, (-1)*config.rocketShape.bodyWidth /*&left_wing_top*/);
	right_wing = new triangle(r_pGame, right_wing_ref, config.rocketShape.bodyWidth, (-1)*config.rocketShape.bodyWidth /*&right_wing_top*/);

	name = 3;
	ref_list[0] = &body_ref.x;
	ref_list[1] = &body_ref.y;
	ref_list[2] = &head_ref.x;
	ref_list[3] = &head_ref.y;
	ref_list[4] = &left_wing_ref.x;
	ref_list[5] = &left_wing_ref.y;


}
rocket::~rocket()
{
	delete body;
	delete head;
	delete left_wing;
	delete right_wing;
}
void rocket::draw() const
{

	body->draw();
	head->draw();
	left_wing->draw();
	right_wing->draw();

}

void rocket::rotate() 
{
	rotationCount++;



	double cos90 = 0;
	double sin90 = 1;

	point refP1, refP2,refP3;
	refP1.x = (head->getRefPoint().x - body->getRefPoint().x) * cos90 - (head->getRefPoint().y - body->getRefPoint().y) * sin90 + body->getRefPoint().x;
	refP1.y = (head->getRefPoint().y - body->getRefPoint().y) * cos90 + (head->getRefPoint().x - body->getRefPoint().x) * sin90 + body->getRefPoint().y;

	refP2.x = (left_wing->getRefPoint().x - body->getRefPoint().x) * cos90 - (left_wing->getRefPoint().y - body->getRefPoint().y) * sin90 + body->getRefPoint().x;
	refP2.y = (left_wing->getRefPoint().y - body->getRefPoint().y) * cos90 + (left_wing->getRefPoint().x - body->getRefPoint().x) * sin90 + body->getRefPoint().y;


	refP3.x = (right_wing->getRefPoint().x - body->getRefPoint().x) * cos90 - (right_wing->getRefPoint().y - body->getRefPoint().y) * sin90 + body->getRefPoint().x;
	refP3.y = (right_wing->getRefPoint().y - body->getRefPoint().y) * cos90 + (right_wing->getRefPoint().x - body->getRefPoint().x) * sin90 + body->getRefPoint().y;

	head_ref = refP1;
	left_wing_ref = refP2;
	right_wing_ref = refP3;



	head->setRefPoint(refP1);
	left_wing->setRefPoint(refP2);
	right_wing->setRefPoint(refP3);




	body->rotate();
	left_wing->rotate();
	right_wing->rotate();
	head->rotate();


}

void rocket::resizeup ()
{
	sizeCount++;

	point top_point = head->getRefPoint();
	point rw_ref = right_wing->getRefPoint();
	point lw_ref = left_wing->getRefPoint();

	point newTopRef = { (top_point.x - RefPoint.x) * config.sizeup + RefPoint.x, (top_point.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point rw_newRef = { (rw_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (rw_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point lw_newRef = { (lw_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (lw_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };


	head->setRefPoint(newTopRef);
	right_wing->setRefPoint(rw_newRef);
	left_wing->setRefPoint(lw_newRef);

	body->resizeup();
	head->resizeup();
	left_wing->resizeup();
	right_wing->resizeup();
	
	if (!check_boundary())
	{
		body->resizedown();
		head->resizedown();
		left_wing->resizedown();
		right_wing->resizedown();
		
		head->setRefPoint(top_point);
		right_wing->setRefPoint(rw_ref);
		left_wing->setRefPoint(lw_ref);

		return;
	}


	head_ref = newTopRef;
	left_wing_ref = rw_newRef;
	right_wing_ref = lw_newRef;
}

void rocket::resizedown ()
{
	sizeCount--;

	point top_point = head->getRefPoint();
	point rw_ref = right_wing->getRefPoint();
	point lw_ref = left_wing->getRefPoint();

	point newTopRef = { (top_point.x - RefPoint.x) * config.sizedown + RefPoint.x, (top_point.y - RefPoint.y) * config.sizedown + RefPoint.y };
	point rw_newRef = { (rw_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (rw_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };
	point lw_newRef = { (lw_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (lw_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	head_ref = newTopRef;
	left_wing_ref = rw_newRef;
	right_wing_ref = lw_newRef;

	head->setRefPoint(newTopRef);
	right_wing->setRefPoint(rw_newRef);
	left_wing->setRefPoint(lw_newRef);

	body->resizedown();
	head->resizedown();
	left_wing->resizedown();
	right_wing->resizedown();

	if (!check_boundary())
	{
		body->resizeup();
		head->resizeup();
		left_wing->resizeup();
		right_wing->resizeup();
		
		head->setRefPoint(top_point);
		right_wing->setRefPoint(rw_ref);
		left_wing->setRefPoint(lw_ref);

		return;
	}

	head_ref = newTopRef;
	left_wing_ref = rw_newRef;
	right_wing_ref = lw_newRef;
}

void rocket::move(arrows direction)
{
	body->move(direction);
	head->move(direction);
	left_wing->move(direction);
	right_wing->move(direction);


	if (!check_boundary())
	{
		body->setRefPoint(RefPoint);
		head->setRefPoint(head_ref);
		left_wing->setRefPoint(left_wing_ref);
		right_wing->setRefPoint(right_wing_ref);
		return;
	}
	RefPoint = body->getRefPoint();

	head_ref = head->getRefPoint();
	left_wing_ref = left_wing->getRefPoint();
	right_wing_ref = right_wing->getRefPoint();
	body_ref = RefPoint;


}

bool rocket::check_boundary()
{
	if (body->check_boundary() && head->check_boundary()
	&& left_wing->check_boundary() && right_wing->check_boundary())
	{
		return true;
	}
	return false;
}







////////////////////////////////////////////////////  class tree  ///////////////////////////////////////

tree::tree(game* r_pGame, point ref) : shape(r_pGame, ref) {
	log_ref = ref;
	leaf_ref = { ref.x,
		ref.y - (config.treeShape.bodyHeight / 2) - (config.treeShape.leafHeight / 2) };

	log = new Rect(r_pGame, log_ref, config.treeShape.bodyHeight, config.treeShape.bodyBase);
	leafs = new triangle(r_pGame, leaf_ref, config.treeShape.leafBase, (-1)*config.treeShape.leafHeight);

	name = 4;
	ref_list[0] = &log_ref.x;
	ref_list[1] = &log_ref.y;
	ref_list[2] = &leaf_ref.x;
	ref_list[3] = &leaf_ref.y;
	
}

tree::~tree()
{
	delete log;
	delete leafs;
}

void tree::draw() const {
	log->draw();
	leafs->draw();
}


void tree::rotate() {
	rotationCount++;

	double cos90 = 0;
	double sin90 = 1;

	point refP1;
	refP1.x = (leafs->getRefPoint().x - log->getRefPoint().x) * cos90 - (leafs->getRefPoint().y - log->getRefPoint().y) * sin90 + log->getRefPoint().x;
	refP1.y = (leafs->getRefPoint().y - log->getRefPoint().y) * cos90 + (leafs->getRefPoint().x - log->getRefPoint().x) * sin90 + log->getRefPoint().y;


	leaf_ref = refP1;

	
	leafs->setRefPoint(leaf_ref);

	log->rotate();
	leafs->rotate();
}



void tree::resizeup() {
	sizeCount++;

	double topHeight = leafs->gethght();
	double baseHeight = log->getheight();

	point top_point = leafs->getRefPoint();
	point newTopRef = { (top_point.x - RefPoint.x) * config.sizeup + RefPoint.x, (top_point.y - RefPoint.y) * config.sizeup + RefPoint.y };


	leafs->setRefPoint(newTopRef);
	log->resizeup();
	leafs->resizeup();
	
	if (!check_boundary())
	{
		leafs->setRefPoint(top_point);
		log->resizedown();
		leafs->resizedown();
		return;
	}


	leaf_ref = newTopRef;
}

void tree::resizedown() 
{
	sizeCount--;

	double topHeight = leafs->gethght();
	double baseHeight = log->getheight();

	point top_point = leafs->getRefPoint();
	point newTopRef = { (top_point.x - RefPoint.x) * config.sizedown + RefPoint.x, (top_point.y - RefPoint.y) * config.sizedown + RefPoint.y };
	
	leafs->setRefPoint(newTopRef);
	log->resizedown();
	leafs->resizedown();

	if (!check_boundary())
	{
		leafs->setRefPoint(top_point);
		log->resizeup();
		leafs->resizeup();
		return;
	}

	leaf_ref = newTopRef;
}

void tree::move(arrows direction)
{
	leafs->move(direction);
	log->move(direction);
	
	if (!check_boundary())
	{
		leafs->setRefPoint(leaf_ref);
		log->setRefPoint(log_ref);
		return;
	}



	RefPoint = log->getRefPoint();
	log_ref = log->getRefPoint();
	leaf_ref = leafs->getRefPoint();


}

bool tree::check_boundary()
{
	if (log->check_boundary() && leafs->check_boundary())
	{
		return true;
	}
	return false;
}

////////////////////////////////////////////////////  class mosque  ///////////////////////////////////////

mosque::mosque(game* r_pGame, point ref) : shape(r_pGame, ref) {
	base_ref = ref;
	left_tower_ref = { ref.x - (config.mosqueShape.base_base / 2) - (config.mosqueShape.tower_base / 2),
	ref.y - (config.mosqueShape.tower_base / 2) };

	right_tower_ref = { ref.x + (config.mosqueShape.base_base / 2) + (config.mosqueShape.tower_base / 2),
	ref.y - (config.mosqueShape.tower_base / 2) };

	left_th_ref = { left_tower_ref.x,
		left_tower_ref.y - (config.mosqueShape.tower_height / 2) - (config.mosqueShape.headt_height / 2) };
	right_th_ref = { right_tower_ref.x, left_th_ref.y };

	oba_ref = { ref.x, ref.y - (config.mosqueShape.base_height / 2) };

	base = new Rect(r_pGame, base_ref, config.mosqueShape.base_height,
		config.mosqueShape.base_base);
	left_tower = new Rect(r_pGame, left_tower_ref, config.mosqueShape.tower_height,
		config.mosqueShape.tower_base);

	right_tower = new Rect(r_pGame, right_tower_ref, config.mosqueShape.tower_height,
		config.mosqueShape.tower_base);

	left_th = new triangle(r_pGame, left_th_ref, config.mosqueShape.headt_base,
		(-1)*config.mosqueShape.headt_height);
	right_th = new triangle(r_pGame, right_th_ref, config.mosqueShape.headt_base,
		(-1)*config.mosqueShape.headt_height);
	oba = new circle(r_pGame, oba_ref, config.mosqueShape.oba_radius);

	name = 5;
	ref_list[0] = &base_ref.x;
	ref_list[1] = &base_ref.y;
	ref_list[2] = &left_tower_ref.x;
	ref_list[3] = &left_tower_ref.y;
	ref_list[4] = &right_th_ref.x;
	ref_list[5] = &right_th_ref.y;
}

mosque::~mosque()
{
	delete oba;
	delete base;
	delete left_tower;
	delete right_tower;
	delete left_th;
	delete right_th;
}


void mosque::draw() const
{
	oba->draw();
	base->draw();
	left_tower->draw();
	right_tower->draw();
	left_th->draw();
	right_th->draw();
}


void mosque::rotate() 
{
	rotationCount++;

	double cos90 = 0;
	double sin90 = 1;

	point refP1, refP2, refP3, refP4, refP5;
	refP1.x = (left_tower->getRefPoint().x - base->getRefPoint().x) * cos90 - (left_tower->getRefPoint().y - base->getRefPoint().y) * sin90 + base->getRefPoint().x;
	refP1.y = (left_tower->getRefPoint().y - base->getRefPoint().y) * cos90 + (left_tower->getRefPoint().x - base->getRefPoint().x) * sin90 + base->getRefPoint().y;

	refP2.x = (right_tower->getRefPoint().x - base->getRefPoint().x) * cos90 - (right_tower->getRefPoint().y - base->getRefPoint().y) * sin90 + base->getRefPoint().x;
	refP2.y = (right_tower->getRefPoint().y - base->getRefPoint().y) * cos90 + (right_tower->getRefPoint().x - base->getRefPoint().x) * sin90 + base->getRefPoint().y;


	refP3.x = (left_th->getRefPoint().x - base->getRefPoint().x) * cos90 - (left_th->getRefPoint().y - base->getRefPoint().y) * sin90 + base->getRefPoint().x;
	refP3.y = (left_th->getRefPoint().y - base->getRefPoint().y) * cos90 + (left_th->getRefPoint().x - base->getRefPoint().x) * sin90 + base->getRefPoint().y;



	refP4.x = (right_th->getRefPoint().x - base->getRefPoint().x) * cos90 - (right_th->getRefPoint().y - base->getRefPoint().y) * sin90 + base->getRefPoint().x;
	refP4.y = (right_th->getRefPoint().y - base->getRefPoint().y) * cos90 + (right_th->getRefPoint().x - base->getRefPoint().x) * sin90 + base->getRefPoint().y;
	
	refP5.x = (oba->getRefPoint().x - base->getRefPoint().x) * cos90 - (oba->getRefPoint().y - base->getRefPoint().y) * sin90 + base->getRefPoint().x;
	refP5.y = (oba->getRefPoint().y - base->getRefPoint().y) * cos90 + (oba->getRefPoint().x - base->getRefPoint().x) * sin90 + base->getRefPoint().y;



	left_tower_ref = refP1;
	right_tower_ref = refP2;
	left_th_ref = refP3;
	right_th_ref = refP4;
	oba_ref = refP5;



	left_tower->setRefPoint(refP1);
	right_tower->setRefPoint(refP2);
	left_th->setRefPoint(refP3);
	right_th->setRefPoint(refP4);
	oba->setRefPoint(refP5);



	base->rotate();
	left_tower->rotate();
	right_tower->rotate();
	left_th->rotate();
	right_th->rotate();
}

void mosque::resizeup() {
	sizeCount++;

	point rt_ref = right_tower->getRefPoint();
	point lt_ref = left_tower->getRefPoint();
	point rth_ref = right_th->getRefPoint();
	point lth_ref = left_th->getRefPoint();
	point oba_ref = oba->getRefPoint();


	point rt_newRef = { (rt_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (rt_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point lt_newRef = { (lt_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (lt_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point rth_newRef = { (rth_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (rth_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point lth_newRef = { (lth_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (lth_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };
	point oba_newRef = { (oba_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (oba_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };

	oba->resizeup();
	base->resizeup();
	left_tower->resizeup();
	right_tower->resizeup();
	left_th->resizeup();
	right_th->resizeup();

	left_tower->setRefPoint(lt_newRef);
	right_tower->setRefPoint(rt_newRef);
	left_th->setRefPoint(lth_newRef);
	right_th->setRefPoint(rth_newRef);
	oba->setRefPoint(oba_newRef);

	if (!check_boundary())
	{
		oba->resizedown();
		base->resizedown();
		left_tower->resizedown();
		right_tower->resizedown();
		left_th->resizedown();
		right_th->resizedown();
	
		left_tower->setRefPoint(lt_ref);
		right_tower->setRefPoint(rt_ref);
		left_th->setRefPoint(lth_ref);
		right_th->setRefPoint(rth_ref);
		oba->setRefPoint(oba_ref);

		return;
	}

	left_tower_ref = lt_newRef;
	right_tower_ref = rt_newRef;
	left_th_ref = lth_newRef;
	right_th_ref = rth_newRef;
	oba_ref = oba_newRef;

}




void mosque::resizedown() 
{
	sizeCount--;

	point rt_ref = right_tower->getRefPoint();
	point rt_newRef = { (rt_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (rt_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };


	point lt_ref = left_tower->getRefPoint();
	point lt_newRef = { (lt_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (lt_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	point rth_ref = right_th->getRefPoint();
	point rth_newRef = { (rth_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (rth_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	point lth_ref = left_th->getRefPoint();
	point lth_newRef = { (lth_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (lth_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	point oba_ref = oba->getRefPoint();
	point oba_newRef = { (oba_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (oba_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	left_tower->setRefPoint(lt_newRef);
	right_tower->setRefPoint(rt_newRef);

	left_th->setRefPoint(lth_newRef);
	right_th->setRefPoint(rth_newRef);

	oba->setRefPoint(oba_newRef);



	left_tower_ref = lt_newRef;
	right_tower_ref = rt_newRef;
	left_th_ref = lth_newRef;
	right_th_ref = rth_newRef;
	oba_ref = oba_newRef;

	oba->resizedown();
	base->resizedown();
	left_tower->resizedown();
	right_tower->resizedown();
	left_th->resizedown();
	right_th->resizedown();
}

void mosque::move(arrows direction)
{
	oba->move(direction);
	base->move(direction);
	left_tower->move(direction);
	right_tower->move(direction);
	left_th->move(direction);
	right_th->move(direction);


	if(!check_boundary())
	{
		oba->setRefPoint(oba_ref);
		base->setRefPoint(base_ref);
		left_tower->setRefPoint(left_tower_ref);
		right_tower->setRefPoint(right_tower_ref);
		left_th->setRefPoint(left_th_ref);
		right_th->setRefPoint(right_th_ref);

		return;
	}


	RefPoint = base->getRefPoint();

	left_tower_ref = left_tower->getRefPoint();
	right_tower_ref = right_tower->getRefPoint();
	left_th_ref = left_th->getRefPoint();
	right_th_ref = right_th->getRefPoint();
	oba_ref = oba->getRefPoint();
	base_ref = RefPoint;
}

bool mosque::check_boundary()
{
	if (oba->check_boundary() && base->check_boundary() &&
		left_tower->check_boundary() && right_tower->check_boundary() &&
		left_th->check_boundary() && right_th->check_boundary())
	{
		return true;
	}
	return false;
}





////////////////////////////////////////////////////  class dumbbell  ///////////////////////////////////////

dumbbell::dumbbell(game* r_pGame, point ref) : shape(r_pGame, ref) {
	handle_ref = ref;
	left_w_ref = { ref.x - (config.dShape.h_Length / 2), ref.y };
	right_w_ref = { ref.x + (config.dShape.h_Length / 2), ref.y };

	handle = new Rect(r_pGame, handle_ref, config.dShape.h_Height, config.dShape.h_Length);
	left_w = new circle(r_pGame, left_w_ref, config.dShape.d_radius);
	right_w = new circle(r_pGame, right_w_ref, config.dShape.d_radius);


	name = 6;
	ref_list[0] = &handle_ref.x;
	ref_list[1] = &handle_ref.y;
	ref_list[2] = &left_w_ref.x;
	ref_list[3] = &left_w_ref.y;
	ref_list[4] = &right_w_ref.x;
	ref_list[5] = &right_w_ref.y;
}
dumbbell::~dumbbell()
{
	delete handle;
	delete left_w;
	delete right_w;
}
void dumbbell::draw() const
{
	handle->draw();
	left_w->draw();
	right_w->draw();

}
void dumbbell::rotate() 
{
	rotationCount++;


	double cos90 = 0;
	double sin90 = 1;
	point refP1, refP2;
	refP1.x = (left_w->getRefPoint().x - handle->getRefPoint().x) * cos90 - (left_w->getRefPoint().y - handle->getRefPoint().y) * sin90 + handle->getRefPoint().x;
	refP1.y = (left_w->getRefPoint().y - handle->getRefPoint().y) * cos90 + (left_w->getRefPoint().x - handle->getRefPoint().x) * sin90 + handle->getRefPoint().y;

	refP2.x = (right_w->getRefPoint().x - handle->getRefPoint().x) * cos90 - (right_w->getRefPoint().y - handle->getRefPoint().y) * sin90 + handle->getRefPoint().x;
	refP2.y = (right_w->getRefPoint().y - handle->getRefPoint().y) * cos90 + (right_w->getRefPoint().x - handle->getRefPoint().x) * sin90 + handle->getRefPoint().y;


	left_w_ref = refP1;
	right_w_ref = refP2;

	left_w->setRefPoint(refP1);
	right_w->setRefPoint(refP2);

	handle->rotate();
	left_w->draw();
	right_w->draw();

}


void dumbbell::resizeup() 
{
	sizeCount++;

	point leftw_ref = left_w->getRefPoint();
	point leftw_newRef = { (leftw_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (leftw_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };

	point rightw_ref = right_w->getRefPoint();
	point rightw_newRef = { (rightw_ref.x - RefPoint.x) * config.sizeup + RefPoint.x, (rightw_ref.y - RefPoint.y) * config.sizeup + RefPoint.y };

	left_w->setRefPoint(leftw_newRef);
	right_w->setRefPoint(rightw_newRef);

	handle->resizeup();
	left_w->resizeup();
	right_w->resizeup();

	if (!check_boundary())
	{
		left_w->setRefPoint(leftw_ref);
		right_w->setRefPoint(rightw_ref);

		handle->resizedown();
		left_w->resizedown();
		right_w->resizedown();
		return;
	}


	left_w_ref = leftw_newRef;
	right_w_ref = rightw_newRef;
}

void dumbbell::resizedown() 
{
	sizeCount--;

	point leftw_ref = left_w->getRefPoint();
	point rightw_ref = right_w->getRefPoint();

	point leftw_newRef = { (leftw_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (leftw_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };
	point rightw_newRef = { (rightw_ref.x - RefPoint.x) * config.sizedown + RefPoint.x, (rightw_ref.y - RefPoint.y) * config.sizedown + RefPoint.y };

	left_w->setRefPoint(leftw_newRef);
	right_w->setRefPoint(rightw_newRef);

	handle->resizedown();
	left_w->resizedown();
	right_w->resizedown();

	if (!check_boundary())
	{
		left_w->setRefPoint(leftw_ref);
		right_w->setRefPoint(rightw_ref);

		handle->resizeup();
		left_w->resizeup();
		right_w->resizeup();
		return;
	}

	left_w_ref = leftw_newRef;
	right_w_ref = rightw_newRef;
}

void dumbbell::move(arrows direction)
{
	handle->move(direction);
	left_w->move(direction);
	right_w->move(direction);

	if (!check_boundary())
	{
		handle->setRefPoint(handle_ref);
		left_w->setRefPoint(left_w_ref);
		right_w->setRefPoint(right_w_ref);
		return;
	}

	RefPoint = handle->getRefPoint();
	left_w_ref = left_w->getRefPoint();
	right_w_ref = right_w->getRefPoint();
	handle_ref = RefPoint;


}

bool dumbbell::check_boundary()
{
	if (left_w->check_boundary() && right_w->check_boundary() && handle->check_boundary())
	{
		return true;
	}
	return false;
}





