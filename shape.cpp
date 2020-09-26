#include "shape.hpp"

Shape::~Shape() {}



Circle::Circle(): center(Vector2D(0, 0)), radius(0) {}

Circle::Circle(const Vector2D &center, float radius): center(center), radius(radius) {}

Circle::Circle(const Circle &other): center(other.center), radius(other.radius) {}

Circle::~Circle() {}

Vector2D Circle::support(const Vector2D &direction) const {
	return center + radius * direction.normalized();
}



Polygon::Polygon(): num_vertices(0), vertices(nullptr) {}

Polygon::Polygon(int num_vertices, const Vector2D *vertices): num_vertices(num_vertices) {
	this->vertices = new Vector2D[num_vertices]; 
	for (int i = 0; i < num_vertices; ++i) {
		this->vertices[i] = vertices[i];
	}
}

Polygon::Polygon(const Polygon &other): num_vertices(other.num_vertices) {
	this->vertices = new Vector2D[num_vertices];
	for (int i = 0; i < num_vertices; ++i) {
		this->vertices[i] = other.vertices[i];
	}
}

Polygon::~Polygon() {
	delete[] vertices;
}

Vector2D Polygon::support(const Vector2D &direction) const {
	Vector2D furthest_vertex;
	float furthest_distance = INT32_MIN;

	for (int i = 0; i < num_vertices; ++i) {
		float distance = vertices[i].dot(direction);
		if (distance > furthest_distance) {
			furthest_distance = distance;
			furthest_vertex = vertices[i];
		}
	}

	return furthest_vertex;
}