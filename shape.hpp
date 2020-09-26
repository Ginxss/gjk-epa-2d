#ifndef TF_SHAPE_H
#define TF_SHAPE_H

#include "vector2d.hpp" // iostream, math

class Shape {
public:
	virtual ~Shape() = 0;
	virtual Vector2D support(const Vector2D &direction) const = 0;
};

class Circle : public Shape {
public:
	Vector2D center;
	float radius;

public:
	Circle();
	Circle(const Vector2D &center, float radius);
	Circle(const Circle &other);
	virtual ~Circle();

	Vector2D support(const Vector2D &direction) const override;
};

class Polygon : public Shape {
public:
	int num_vertices;
	Vector2D *vertices;

public:
	Polygon();
	Polygon(int num_vertices, const Vector2D *vertices);
	Polygon(const Polygon &other);
	virtual ~Polygon();

	Vector2D support(const Vector2D &direction) const override;
};

#endif