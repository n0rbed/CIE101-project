#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}


////////////////////////////////////////////////////  class ice cream  ///////////////////////////////////////
iceCream::iceCream(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point circle_ref = ref;
	double triangle_offset = config.iceShape.radius * 1.2;

	point triangle_ref = { ref.x, ref.y + triangle_offset};
	cream = new circle(pGame, circle_ref, config.iceShape.radius);
	cone = new triangle(pGame, triangle_ref, 2 * config.iceShape.radius, config.iceShape.triangle_height);
}

void iceCream::draw() const
{
	cream->draw();
	cone->draw();
}





////////////////////////////////////////////////////  class car  ///////////////////////////////////////
car::car(game* r_pGame, point ref) : shape(r_pGame, ref) 
{
	point body_ref = ref;

	point left_wheel_ref = { ref.x - (config.carShape.body_width/2) + config.carShape.wheel_radius,
	(ref.y + (config.carShape.body_height/3) + config.carShape.wheel_radius) };

	point right_wheel_ref = { ref.x + (config.carShape.body_width/2) - config.carShape.wheel_radius,
	ref.y + (config.carShape.body_height/3) + config.carShape.wheel_radius };

	left_wheel = new circle(pGame, left_wheel_ref, config.carShape.wheel_radius);
	right_wheel = new circle(pGame, right_wheel_ref, config.carShape.wheel_radius);
	body = new Rect(pGame, body_ref, config.carShape.body_height, config.carShape.body_width);

}

void car::draw() const
{
	left_wheel->draw();
	right_wheel->draw();
	body->draw();
}


////////////////////////////////////////////////////  class rocket  ///////////////////////////////////////
rocket::rocket(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	point body_ref = ref;
	point head_ref = { ref.x, ref.y - (config.rocketShape.bodyHeight / 2) - (config.rocketShape.headHeight / 2) };

	point left_wing_ref = { ref.x - (config.rocketShape.bodyWidth / 2) - (config.rocketShape.wingBase / 2),
		ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.bodyWidth / 1.9)};

	point left_wing_top = { ref.x - (config.rocketShape.bodyWidth / 2),
		ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.wingBase) };

	point right_wing_ref = { ref.x + (config.rocketShape.bodyWidth / 2) + (config.rocketShape.wingBase / 2),
		ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.wingBase / 1.9)};

	point right_wing_top = { ref.x + (config.rocketShape.bodyWidth / 2),
		ref.y + (config.rocketShape.bodyHeight / 2) - (config.rocketShape.wingBase) };

	body = new Rect(r_pGame, body_ref, config.rocketShape.bodyHeight, config.rocketShape.bodyWidth);
	head = new triangle(r_pGame, head_ref, config.rocketShape.bodyWidth, (-1)*config.rocketShape.headHeight);
	left_wing = new triangle(r_pGame, left_wing_ref, config.rocketShape.bodyWidth, (-1)*config.rocketShape.bodyWidth, &left_wing_top);
	right_wing = new triangle(r_pGame, right_wing_ref, config.rocketShape.bodyWidth, (-1)*config.rocketShape.bodyWidth, &right_wing_top);

}
void rocket::draw() const
{

	body->draw();
	head->draw();
	left_wing->draw();
	right_wing->draw();

}

////////////////////////////////////////////////////  class tree  ///////////////////////////////////////

tree::tree(game* r_pGame, point ref) : shape(r_pGame, ref) {
	point log_ref = ref;
	point leaf_ref = { ref.x,
		ref.y - (config.treeShape.bodyHeight / 2) - (config.treeShape.leafHeight / 2) };

	log = new Rect(r_pGame, log_ref, config.treeShape.bodyHeight, config.treeShape.bodyBase);
	leafs = new triangle(r_pGame, leaf_ref, config.treeShape.leafBase, (-1)*config.treeShape.leafHeight);


}

void tree::draw() const {
	log->draw();
	leafs->draw();
}


////////////////////////////////////////////////////  class castle  ///////////////////////////////////////

mosque::mosque(game* r_pGame, point ref) : shape(r_pGame, ref) {
	point base_ref = ref;
	point left_tower_ref = { ref.x - (config.mosqueShape.base_base / 2) - (config.mosqueShape.tower_base / 2),
	ref.y - (config.mosqueShape.tower_base / 2) };

	point right_tower_ref = { ref.x + (config.mosqueShape.base_base / 2) + (config.mosqueShape.tower_base / 2),
	ref.y - (config.mosqueShape.tower_base / 2) };

	point left_th_ref = { left_tower_ref.x,
		left_tower_ref.y - (config.mosqueShape.tower_height / 2) - (config.mosqueShape.headt_height / 2) };
	point right_th_ref = { right_tower_ref.x, left_th_ref.y };

	point oba_ref = { ref.x, ref.y - (config.mosqueShape.base_height / 2) };

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
