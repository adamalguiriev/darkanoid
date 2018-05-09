#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
class Ball
{
public:
	Ball(Vec2& _center, float _radius);

	void TestWallsCollision(RectF& walls);

	void Update(float dt);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;

private:
	Vec2 pos; //position
	Vec2 vel = Vec2(1.0f, .0f); //velocity
	float radius;
	float speed = 120.0f;
};