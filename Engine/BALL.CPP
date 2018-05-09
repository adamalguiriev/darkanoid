#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2& _center, float _radius)
{
	pos = _center;
	radius = _radius;
}

void Ball::TestWallsCollision(RectF & walls)
{
	RectF rect = GetRect();

	if (rect.left < walls.left)	
	{
		vel.x *= -1;
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		vel.x *= -1;
		pos.x -= rect.right - walls.right;
	}

	if (rect.top < walls.top)
	{
		vel.y *= -1;
		pos.y += walls.top - rect.top;
	}
	else if (rect.bottom > walls.bottom)
	{
		vel.y *= -1;
		pos.y -= rect.bottom - walls.bottom;
	}
}

void Ball::Update(float dt)
{
	pos += vel.GetNormalized() * speed * dt;
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
	//gfx.DrawRect(GetRect(), Colors::Red);
	//gfx.PutPixel(pos.x, pos.y, Colors::Blue);
}

RectF Ball::GetRect() const
{
	RectF rect = RectF::FromCenter(pos, radius, radius);

	return rect;
}
