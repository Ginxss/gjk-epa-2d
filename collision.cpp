#include "collision.hpp"

bool intersect(const Shape &shape1, const Shape &shape2, Vector2D *penetration) {
	if (!penetration) {
		return gjk_intersect(shape1, shape2);
	}

	Simplex simplex;
	if (gjk_intersect(shape1, shape2, &simplex)) {
		*penetration = epa_penetration(shape1, shape2, simplex);
		return true;
	}
	return false;
}