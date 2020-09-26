#ifndef TF_GJK_H
#define TF_GJK_H

#include "shape.hpp" // vector2d, iostream, math

struct Simplex {
	Vector2D elements[3];
	int index;
};

Vector2D support(const Shape &shape1, const Shape &shape2, const Vector2D &direction);
bool gjk_intersect(const Shape &shape1, const Shape &shape2, Simplex *simplex_to_fill = nullptr);

#endif