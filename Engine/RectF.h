#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(Vec2& topLeft, Vec2& bottomRight);
	RectF(float _left, float _right, float _top, float _bottom);
	RectF(Vec2& topLeft, float width, float height);

	bool IsOverlappingWith(RectF& other) const;

	static RectF& FromCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float left;
	float right;
	float top;
	float bottom;
};