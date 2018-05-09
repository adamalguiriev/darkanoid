#include "RectF.h"

RectF::RectF(Vec2 & topLeft, Vec2 & bottomRight)
{
	left = topLeft.x;
	right = bottomRight.x;
	top = topLeft.y;
	bottom = bottomRight.y;
}

RectF::RectF(float _left, float _right, float _top, float _bottom)
{
	left = _left;
	right = _right;
	top = _top;
	bottom = _bottom;
}

RectF::RectF(Vec2 & topLeft, float width, float height)
{
	left = topLeft.x;
	right = left + width;
	top = topLeft.y;
	bottom = top + height;
}

bool RectF::IsOverlappingWith(RectF & other) const
{
	return (

		left < other.right &&
		bottom > other.top &&
		right > other.left &&
		top < other.bottom
		);
}

RectF & RectF::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	RectF rect = RectF(center - Vec2(halfWidth, halfHeight), center + Vec2(halfWidth, halfHeight));

	return rect;
}
