#include "vector2d.hpp"

Vector2D::Vector2D(): x(0), y(0) {}

Vector2D::Vector2D(float x, float y): x(x), y(y) {}

Vector2D::Vector2D(const Vector2D &v): x(v.x), y(v.y) {}

Vector2D &Vector2D::operator=(const Vector2D &v) {
	x = v.x;
	y = v.y;
	return *this;
}



Vector2D Vector2D::operator+(const Vector2D &v) const {
	return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v) const {
	return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator*(const Vector2D &v) const {
	return Vector2D(x * v.x, y * v.y);
}

Vector2D Vector2D::operator/(const Vector2D &v) const {
	float result_x = (v.x != 0) ? (x / v.x) : x;
	float result_y = (v.y != 0) ? (y / v.y) : y;
	return Vector2D(result_x, result_y);
}

void Vector2D::operator+=(const Vector2D &v) {
	x += v.x;
	y += v.y;
}

void Vector2D::operator-=(const Vector2D &v) {
	x -= v.x;
	y -= v.y;
}

void Vector2D::operator*=(const Vector2D &v) {
	x *= v.x;
	y *= v.y;
}

void Vector2D::operator/=(const Vector2D &v) {
	if (v.x != 0) x /= v.x;
	if (v.y != 0) y /= v.y;
}



Vector2D Vector2D::operator+(const float f) const {
	return Vector2D(x + f, y + f);
}

Vector2D Vector2D::operator-(const float f) const {
	return Vector2D(x - f, y - f);
}

Vector2D Vector2D::operator*(const float f) const {
	return Vector2D(x * f, y * f);
}

Vector2D Vector2D::operator/(const float f) const {
	float result_x = x;
	float result_y = y;
	if (f != 0) {
		result_x /= f;
		result_y /= f;
	}

	return Vector2D(result_x, result_y);
}

void Vector2D::operator+=(const float f) {
	x += f;
	y += f;
}

void Vector2D::operator-=(const float f) {
	x -= f;
	y -= f;
}

void Vector2D::operator*=(const float f) {
	x *= f;
	y *= f;
}

void Vector2D::operator/=(const float f) {
	if (f != 0) {
		x /= f;
		y /= f;
	}
}

Vector2D operator+(const float f, const Vector2D &v) {
	return v + f;
}

Vector2D operator*(const float f, const Vector2D &v) {
	return v * f;
}



Vector2D Vector2D::operator-() const {
	return Vector2D(-x, -y);
}



float Vector2D::length() const {
	return sqrtf(x*x + y*y);
}

float Vector2D::length_squared() const {
	return x*x + y*y;
}

void Vector2D::normalize() {
	(*this) /= length();
}

Vector2D Vector2D::normalized() const {
	return (*this) / length();
}

Vector2D Vector2D::round(int decimal_places) const {
	float factor = powf(10, decimal_places);
	float result_x = ((int)(x * factor + 0.5)) / factor;
	float result_y = ((int)(y * factor + 0.5)) / factor;
	return Vector2D(result_x, result_y);
}



bool Vector2D::operator==(const Vector2D &v) const {
	return x == v.x && y == v.y;
}

bool Vector2D::operator!=(const Vector2D &v) const {
	return x != v.x || y != v.y;
}

bool Vector2D::operator<(const Vector2D &v) const {
	return length_squared() < v.length_squared();
}

bool Vector2D::operator>(const Vector2D &v) const {
	return length_squared() > v.length_squared();
}

bool Vector2D::is_null() const {
	return x == 0 && y == 0;
}



float Vector2D::dot(const Vector2D &v) const {
	return x * v.x + y * v.y;
}

Vector2D Vector2D::projection_on(const Vector2D &v) const {
	if (v.is_null()) {
		return *this;
	}

	return (this->dot(v) / v.length_squared()) * v;
}



Vector2D Vector2D::perpendicular_clockwise() const {
	return Vector2D(y, -x);
}

Vector2D Vector2D::perpendicular_counterclockwise() const {
	return Vector2D(-y, x);
}

Vector2D perpendicular_towards(const Vector2D &a, const Vector2D &b, const Vector2D &p) {
	Vector2D ab = b - a;
    Vector2D ap = p - a;

	Vector2D result = ab.perpendicular_clockwise();
	if (result.dot(ap) > 0) {
		return result;
	}
	else {
		return -result;
	}
}

Vector2D perpendicular_away(const Vector2D &a, const Vector2D &b, const Vector2D &p) {
	return -perpendicular_towards(a, b, p);
}



std::ostream &operator<<(std::ostream &os, const Vector2D &v) {
    os << "(" << v.x << "," << v.y << ")";
    return os;
}