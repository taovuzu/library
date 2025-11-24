Below is the exact Markdown content without any changes:

---

# Computational Geometry: Line and Segment Intersections with Mathematical Proofs

## 1. Line-Line Intersection

### Mathematical Proof

A line in 2D can be expressed in the standard (or implicit) form:
\[
a_1x + b_1y = c_1
\]
\[
a_2x + b_2y = c_2
\]

To find the intersection point \((x, y)\) of these two lines, consider the system of equations. This system can be solved using determinants (Cramer's rule). First, compute the determinant of the coefficient matrix:
\[
D =
\begin{vmatrix} 
a_1 & b_1 \\ 
a_2 & b_2 
\end{vmatrix}
= a_1b_2 - a_2b_1
\]

- **Case 1: \( D = 0 \)**
  - The lines are either **parallel** (no intersection) or **coincident** (infinitely many intersections).

- **Case 2: \( D \neq 0 \)**
  - There is exactly one solution (one intersection point), and by applying Cramer’s rule we get:
    \[
    x = \frac{c_1b_2 - c_2b_1}{D}, \quad y = \frac{a_1c_2 - a_2c_1}{D}
    \]

### C++ Code Implementation

```cpp
#include <iostream>
#include <cmath>

const double EPS = 1e-9;

bool lineIntersection(double a1, double b1, double c1, 
                      double a2, double b2, double c2, 
                      double &x, double &y) {
    double D = a1 * b2 - a2 * b1;
    
    if (fabs(D) < EPS) 
        return false;  // Lines are parallel or coincident

    x = (c1 * b2 - c2 * b1) / D;
    y = (a1 * c2 - a2 * c1) / D;
    
    return true;
}

int main() {
    double x, y;
    if (lineIntersection(1, -1, 0, 1, 1, 2, x, y))
        std::cout << "Intersection at: (" << x << ", " << y << ")\n";
    else
        std::cout << "No intersection\n";
    return 0;
}
```

---

## 2. Segment-Segment Intersection

For two segments, we want to determine not only if the infinite lines intersect but if the intersection point lies within both segments.

### Parametric Representation

A segment from point \(A\) to \(B\) can be represented as:
\[
P(t) = A + t (B - A), \quad t \in [0,1]
\]

Given two segments:
- **Segment 1:** \(A\) to \(B\)
- **Segment 2:** \(C\) to \(D\)

The intersection point (if it exists) satisfies:
\[
A + t_1 (B - A) = C + t_2 (D - C)
\]

This leads to two equations (one for each coordinate):
\[
x_A + t_1 (x_B - x_A) = x_C + t_2 (x_D - x_C)
\]
\[
y_A + t_1 (y_B - y_A) = y_C + t_2 (y_D - y_C)
\]

Rewriting in matrix form, we have:
[ (xB - xA)   -(xD - xC) ]   [ t1 ]   =   [ xC - xA ]
[ (yB - yA)   -(yD - yC) ]   [ t2 ]       [ yC - yA ]


The determinant for this system is:
\[
D = (x_B - x_A)(y_C - y_D) - (y_B - y_A)(x_C - x_D)
\]

- **If \(D = 0\):** The segments lie on parallel or identical lines.
- **If \(D \neq 0\):** We can solve for \(t_1\) and \(t_2\) using Cramer’s rule:
  \[
  t_1 = \frac{(x_C - x_A)(y_C - y_D) - (y_C - y_A)(x_C - x_D)}{D}
  \]
  \[
  t_2 = \frac{(y_C - y_A)(x_B - x_A) - (x_C - x_A)(y_B - y_A)}{D}
  \]

The segments intersect if and only if:
\[
0 \leq t_1 \leq 1 \quad \text{and} \quad 0 \leq t_2 \leq 1
\]
And the intersection point is:
\[
P = A + t_1 (B - A)
\]

### C++ Code Implementation Using Complex Numbers

```cpp
#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

typedef complex<double> Point;

// Cross product defined via complex numbers.
// It computes the z-component of the 3D cross product.
double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

bool doSegmentsIntersect(Point a, Point b, Point c, Point d, Point &intersection) {
    double d1 = crossProduct(a - b, d - c);
    double d2 = crossProduct(a - c, d - c);
    double d3 = crossProduct(a - b, a - c);

    if (fabs(d1) < EPS)
        return false;  // Lines are parallel or identical

    double t1 = d2 / d1;
    double t2 = d3 / d1;

    intersection = a + (b - a) * t1;

    // Check if the intersection lies on both segments.
    return (t1 >= -EPS && t1 <= 1 + EPS && t2 >= -EPS && t2 <= 1 + EPS);
}

int main() {
    Point a(0, 0), b(4, 4), c(0, 4), d(4, 0), intersection;
    if (doSegmentsIntersect(a, b, c, d, intersection))
        cout << "Segments Intersect at: (" << intersection.real() << ", " 
             << intersection.imag() << ")\n";
    else
        cout << "Segments do not intersect\n";
    return 0;
}
```

---

## 3. Counter-Clockwise (CCW) Test

### Mathematical Proof

The CCW (counter-clockwise) test helps determine the orientation of three points \(A\), \(B\), and \(C\). Compute the following determinant:
\[
\text{CCW}(A, B, C) = (x_B - x_A)(y_C - y_A) - (y_B - y_A)(x_C - x_A)
\]

- **If \(\text{CCW}(A, B, C) > 0\):** The sequence \(A \rightarrow B \rightarrow C\) makes a counter-clockwise turn.
- **If \(\text{CCW}(A, B, C) < 0\):** It makes a clockwise turn.
- **If \(\text{CCW}(A, B, C) = 0\):** The points are collinear.

### C++ Code Implementation

```cpp
#include <iostream>
#include <complex>

using namespace std;

typedef complex<double> Point;

const double EPS = 1e-9;

double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

int ccw(Point a, Point b, Point c) {
    Point v1 = b - a, v2 = c - a;
    double t = crossProduct(v1, v2);
    
    if (t > EPS) return +1; // Counter-clockwise
    if (t < -EPS) return -1; // Clockwise
    return 0; // Collinear
}

int main() {
    Point a(0, 0), b(10, 0);
    cout << "ccw(a, b, (20,10)): " << ccw(a, b, Point(20, 10)) << "\n"; // +1 => CCW
    cout << "ccw(a, b, (20,-10)): " << ccw(a, b, Point(20, -10)) << "\n"; // -1 => CW
    cout << "ccw(a, b, (5,0)): " << ccw(a, b, (a + b) / 2.0) << "\n"; // 0 => Collinear
    return 0;
}
```

---

## 4. CCW-Based Segment Intersection Test

### Mathematical Proof

A useful method to check if two segments \(P_1P_2\) and \(Q_1Q_2\) intersect is based on the CCW test. The segments intersect if and only if the following conditions hold:
\[
\text{CCW}(P_1, P_2, Q_1) \times \text{CCW}(P_1, P_2, Q_2) \leq 0
\]
\[
\text{CCW}(Q_1, Q_2, P_1) \times \text{CCW}(Q_1, Q_2, P_2) \leq 0
\]

These conditions ensure that:
- Points \(Q_1\) and \(Q_2\) lie on opposite sides of the line through \(P_1P_2\).
- Points \(P_1\) and \(P_2\) lie on opposite sides of the line through \(Q_1Q_2\).

If both conditions are satisfied, then the segments must cross.

---

## Conclusion

- **Line-Line Intersection:** We solve a 2×2 system using determinants. If the determinant is zero, the lines are parallel or identical; otherwise, the intersection is given by Cramer’s rule.
- **Segment-Segment Intersection:** By representing each segment parametrically, we solve for the parameters. The segments intersect if these parameters lie within \([0, 1]\).
- **CCW Test:** Determines the orientation of three points using the cross product (determinant).
- **CCW-Based Intersection Test:** Uses the CCW results to verify that endpoints of one segment lie on opposite sides of the other segment's line.

This document provides the detailed mathematical proofs along with corresponding C++ code implementations.