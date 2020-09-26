# gjk-epa-2d
**GJK (Gilbert–Johnson–Keerthi) and EPA (Expanding Polytope Algorithm) in 2D**
___

Just collision detection:
```
#include "collision.hpp"

if (intersect(shape1, shape2)) {
    // shape1 and shape2 intersect
}
```

___

You can provide a penetration vector to be filled out as well:
```
#include "collision.hpp"

Vector2D penetration;
if (intersect(shape1, shape2, &penetration)) {
    // Move shape1 by -penetration or shape2 by penetration to avoid collision
}
```

---

Of course, the penetration vector needs to be a `Vector2D` and the tested shapes need to be derivatives of the class `Shape`.

New derivatives of Shape can easily be added, they just need to provide a support function.