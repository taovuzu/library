# Computational Geometry: Lines and Distances with Mathematical Proofs

This document covers several fundamental concepts in computational geometry related to lines, rays, segments, and distances. We explain the mathematical proofs behind each concept and provide corresponding C++ code for demonstration.

---

## 1. Double Comparison and Epsilon

Floating-point comparisons can be tricky due to precision issues. In many geometric algorithms, a small value (commonly denoted as **EPS**) is used to decide when two doubles are considered equal. For example, one checks if  
$$
|x - y| < \text{EPS}
$$  
to decide if \(x\) and \(y\) are equal.

---

## 2. Line, Ray, and Segment Representations

### 2.1. Parametric Equation for a Segment

A segment with endpoints \(P_0\) and \(P_1\) can be expressed parametrically as:
$$
P(t) = P_0 + t (P_1 - P_0), \quad t \in [0, 1]
$$
- When \(t = 0\), \(P(t) = P_0\).
- When \(t = 1\), \(P(t) = P_1\).
- If \(t\) lies outside \([0, 1]\), the point is on the extended line but not on the segment.

### 2.2. Converting Between Representations

A line may be given in standard form (e.g., \(ax + by = c\)), but the parametric form is often preferred in computational geometry because it easily lets you check for points lying on the segment and compute distances.

---

## 3. Checking Collinearity and Point Position

### 3.1. Collinearity (Is Point C on Line A–B?)

Three points \(A\), \(B\), and \(C\) are collinear if the vector cross product is zero:
$$
\text{Cross}(B-A, C-A) = 0.
$$
Since the cross product in 2D is given by
$$
\text{Cross}(v, w) = v_x w_y - v_y w_x,
$$
we say \(C\) lies on the line \(AB\) if:
$$
\left| \text{Cross}(B-A, C-A) \right| < \text{EPS}.
$$

### 3.2. Point on a Ray (Is Point C on Ray A–B?)

Point \(C\) is on the ray originating at \(A\) in the direction of \(B\) if:
1. \(C\) is collinear with \(A\) and \(B\), and
2. The direction from \(A\) to \(C\) is the same as that from \(A\) to \(B\).  
   A common check is to verify that the normalized vectors are equal (or the dot product is nonnegative).

### 3.3. Point on a Segment (Is Point C on Segment A–B?)

For point \(C\) to lie on the segment \(AB\), it must lie on the ray \(A \to B\) and also on the ray \(B \to A\). Equivalently, you can check:
$$
\text{distance}(A, C) + \text{distance}(C, B) \approx \text{distance}(A, B).
$$

---

## 4. Distance Calculations

### 4.1. Distance from a Point to a Line

Given a line through \(P_0\) and \(P_1\) and a point \(P_2\), the distance from \(P_2\) to the infinite line is:
$$
d = \frac{\left| \text{Cross}(P_1-P_0, P_2-P_0) \right|}{\left|P_1-P_0\right|}.
$$

### 4.2. Distance from a Point to a Segment

To compute the distance from a point \(P_2\) to the segment \(P_0P_1\):
- **Project \(P_2\) onto the line:** Compute 
  $$
  t = \frac{(P_2-P_0) \cdot (P_1-P_0)}{|P_1-P_0|^2}.
  $$
- **If \(t\) is between 0 and 1:** The projection lies on the segment and the distance is as above (using the perpendicular distance).
- **If \(t < 0\) or \(t > 1\):** The closest point is one of the endpoints, and the distance is the minimum of \(|P_2-P_0|\) or \(|P_2-P_1|\).

---

### **Summary Formula:**

Let:

* $\mathbf{v} = \mathbf{P}_1 - \mathbf{P}_0$
* $\mathbf{w} = \mathbf{P}_2 - \mathbf{P}_0$
* $t = \frac{\mathbf{w} \cdot \mathbf{v}}{\|\mathbf{v}\|^2}$

Then:

$$
\text{distance} =
\begin{cases}
\|\mathbf{P}_2 - (\mathbf{P}_0 + t \mathbf{v})\| & \text{if } 0 \leq t \leq 1 \\
\min(\|\mathbf{P}_2 - \mathbf{P}_0\|, \|\mathbf{P}_2 - \mathbf{P}_1\|) & \text{otherwise}
\end{cases}
$$


## 5. C++ Code Implementation

Below is a simplified version of the C++ code (without macros) that implements the concepts discussed above:

```cpp
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;  // Epsilon for floating-point comparisons

typedef complex<double> Point;

// Compute the length of a vector (point)
double getLength(Point a) {
    return hypot(a.real(), a.imag());
}

// Dot product of two vectors
double dotProduct(Point a, Point b) {
    return (conj(a) * b).real();
}

// Cross product (z-component) of two vectors
double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

// Normalize a vector
Point normalize(Point a) {
    return a / getLength(a);
}

// Check if three points are collinear
bool isCollinear(Point a, Point b, Point c) {
    return fabs(crossProduct(b - a, c - a)) < EPS;
}

// Check if point C lies on the ray starting at A in direction B-A
bool isPointOnRay(Point A, Point B, Point C) {
    if (getLength(C - A) < EPS) return true;
    return (fabs(getLength(normalize(B - A) - normalize(C - A))) < EPS);
}

// Check if point C lies on the segment AB
bool isPointOnSegment(Point A, Point B, Point C) {
    double totalLength = getLength(B - A);
    double d1 = getLength(C - A);
    double d2 = getLength(B - C);
    return fabs(totalLength - (d1 + d2)) < EPS;
}

// Compute the distance from point P2 to the infinite line through P0 and P1
double distanceToLine(Point P0, Point P1, Point P2) {
    return fabs(crossProduct(P1 - P0, P2 - P0)) / getLength(P1 - P0);
}

// Compute the distance from point P2 to the segment P0-P1
double distanceToSegment(Point P0, Point P1, Point P2) {
    Point v = P1 - P0;
    Point w = P2 - P0;
    
    double d1 = dotProduct(v, w);
    if (d1 <= 0)
        return getLength(P2 - P0);
    
    double d2 = dotProduct(v, v);
    if (d2 <= d1)
        return getLength(P2 - P1);
    
    double t = d1 / d2;
    Point projection = P0 + v * t;
    return getLength(P2 - projection);
}

int main() {
    // Example usage:
    Point A(2, 0), B(10, 0);
    Point C(6, 3); // A point above the segment
    
    // Check if C is collinear with A and B
    cout << "Is C collinear with A and B? " << (isCollinear(A, B, C) ? "Yes" : "No") << "\n";
    
    // Check if C is on the segment A-B
    cout << "Is C on segment A-B? " << (isPointOnSegment(A, B, C) ? "Yes" : "No") << "\n";
    
    // Compute distance from C to line A-B
    cout << "Distance from C to line A-B: " << distanceToLine(A, B, C) << "\n";
    
    // Compute distance from C to segment A-B
    cout << "Distance from C to segment A-B: " << distanceToSegment(A, B, C) << "\n";
    
    return 0;
}
```

---

## Conclusion

- **Double Comparison:** Using an epsilon value is essential for reliable floating-point comparisons.
- **Representations:** Lines, rays, and segments can be represented parametrically.
- **Collinearity and Position Tests:** Check collinearity via the cross product, determine if a point lies on a ray using vector normalization, and verify a point lies on a segment by comparing distances.
- **Distance Calculations:**  
  - The perpendicular distance from a point to a line is given by the magnitude of the cross product divided by the length of the base vector.
  - The distance to a segment is computed by projecting the point onto the line and checking if the projection falls within the segment bounds.

This document provides both the mathematical foundations and a working C++ implementation for these essential geometric operations. Let me know if you need further details or clarifications!