#ifndef TF_VECTOR_H
#define TF_VECTOR_H

#include <iostream>
#include <cmath>

class Vector2D {
public:
	float x;
	float y;

public:
	Vector2D();
	Vector2D(float x, float y);
	Vector2D(const Vector2D &v);
	Vector2D &operator=(const Vector2D &v);

	Vector2D operator+(const Vector2D &v) const;
	Vector2D operator-(const Vector2D &v) const;
	Vector2D operator*(const Vector2D &v) const;
	Vector2D operator/(const Vector2D &v) const;
	void operator+=(const Vector2D &v);
	void operator-=(const Vector2D &v);
	void operator*=(const Vector2D &v);
	void operator/=(const Vector2D &v);

	Vector2D operator+(const float f) const;
	Vector2D operator-(const float f) const;
	Vector2D operator*(const float f) const;
	Vector2D operator/(const float f) const;
	void operator+=(const float f);
	void operator-=(const float f);
	void operator*=(const float f);
	void operator/=(const float f);

	Vector2D operator-() const;

	float length() const;
	float length_squared() const;
	void normalize();
	Vector2D normalized() const;
	Vector2D round(int decimal_places) const;

	bool operator==(const Vector2D &v) const;
	bool operator!=(const Vector2D &v) const;
	bool operator<(const Vector2D &v) const;
	bool operator>(const Vector2D &v) const;
	bool is_null() const;

	float dot(const Vector2D &v) const;
	Vector2D projection_on(const Vector2D &v) const;

	Vector2D perpendicular_clockwise() const;
	Vector2D perpendicular_counterclockwise() const;

	friend std::ostream &operator<<(std::ostream &os, const Vector2D &v);
};

Vector2D operator+(const float f, const Vector2D &v);
Vector2D operator*(const float f, const Vector2D &v);

// returns a perpendicular vector to ab that points towards p (or in the same direction as "ap")
Vector2D perpendicular_towards(const Vector2D &a, const Vector2D &b, const Vector2D &p);
// returns a perpendicular vector to ab that points away from p (or in the opposite direction as "ap")
Vector2D perpendicular_away(const Vector2D &a, const Vector2D &b, const Vector2D &p);

#endif