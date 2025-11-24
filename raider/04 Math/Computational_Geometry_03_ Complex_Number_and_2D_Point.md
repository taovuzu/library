# Computational Geometry: Complex Numbers and 2D Points with Mathematical Proofs

Complex numbers can naturally represent 2D points and vectors. In this document, we explain the mathematical foundations behind using complex numbers for geometric operations and then provide corresponding C++ code examples.

---

## 1. Complex Numbers as 2D Points

A complex number \( z = x + iy \) corresponds to a 2D point with coordinates \((x, y)\). Many operations on points can be implemented directly using complex arithmetic.

### 1.1. Cartesian and Polar Representations

- **Cartesian Form:** \( z = x + iy \)
- **Polar Form:** \( z = r \cdot e^{i\theta} \)  
  where \( r = \sqrt{x^2 + y^2} \) and \(\theta = \tan^{-1}(y/x) \).

The Euler formula connects these representations:
$$
e^{i\theta} = \cos\theta + i\sin\theta.
$$

---

## 2. Fundamental Operations

### 2.1. Dot Product and Cross Product

For two complex numbers (points/vectors) \( a \) and \( b \):

- **Dot Product:**  
  Given by the real part of the product with conjugation:
  $$
  \text{dot}(a, b) = \Re(\overline{a} \cdot b).
  $$
  This is equivalent to \( x_a x_b + y_a y_b \).

- **Cross Product:**  
  In 2D the cross product is a scalar representing the z-component:
  $$
  \text{cross}(a, b) = \Im(\overline{a} \cdot b).
  $$
  This equals \( x_a y_b - y_a x_b \).

### 2.2. Vector Operations

- **Addition/Subtraction:**  
  \( a + b \) and \( a - b \) correspond to the vector sum and difference.
- **Scalar Multiplication:**  
  Multiplying \( a \) by a real number scales the vector.
- **Length (Magnitude):**  
  The length of \( a \) is given by:
  $$
  |a| = \sqrt{x_a^2 + y_a^2}.
  $$
  In C++, it is common to use `hypot` to avoid overflow.

- **Normalization:**  
  The unit vector in the direction of \( a \) is:
  $$
  \frac{a}{|a|}.
  $$

### 2.3. Angle and Rotation

- **Angle of a Complex Number:**  
  The angle \(\theta\) is computed by:
  $$
  \theta = \arctan\left(\frac{y}{x}\right).
  $$
- **Rotation:**  
  To rotate a point \( p \) around the origin by an angle \(\phi\), use:
  $$
  p_{\text{rot}} = p \cdot e^{i\phi}.
  $$
- **Rotation Around Another Point:**  
  To rotate \( p \) around point \( a \) by \(\phi\):
  $$
  p_{\text{rot}} = a + (p - a) \cdot e^{i\phi}.
  $$

### 2.4. Reflection

Reflection of a point \( p \) about a line defined by two points \( p_0 \) and \( p_1 \) can be derived using complex conjugation. In one common approach:
$$
\text{reflect}(p) = p_0 + \overline{\frac{p - p_0}{p_1 - p_0}} \cdot (p_1 - p_0).
$$

---

## 3. Angle Between Vectors

To compute the minimum angle between two vectors \( v_1 \) and \( v_2 \):
$$
\theta = \arccos\left(\frac{\text{dot}(v_1, v_2)}{|v_1|\,|v_2|}\right).
$$

Sometimes, to ensure numerical stability, the value inside \(\arccos\) is clamped to the range \([-1,1]\).

---

## 4. C++ Code Implementation

Below is the “simple version” C++ code that implements these operations without using macros. It includes functions for dot and cross products, computing angles, rotating points, and reflecting a point.

```cpp
#include <iostream>
#include <cmath>
#include <complex>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef complex<double> Point;

// Compute dot product of two vectors (points)
double dotProduct(Point a, Point b) {
    return (conj(a) * b).real();
}

// Compute cross product (z-component) of two vectors
double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

// Compute the angle (in radians) of a complex number (point)
double getAngle(Point a) {
    return atan2(a.imag(), a.real());
}

// Compute the vector from point A to point B
Point getVector(Point A, Point B) {
    return B - A;
}

// Check if two points are the same (within an epsilon tolerance)
bool areSame(Point p1, Point p2) {
    return norm(getVector(p1, p2)) < EPS;
}

// Compute the length (magnitude) of a vector (point)
double getLength(Point a) {
    return hypot(a.imag(), a.real());
}

// Normalize a vector (convert to a unit vector)
Point normalize(Point a) {
    return a / getLength(a);
}

// Rotate a point P around the origin by a given angle (radians)
Point rotateAroundOrigin(Point p, double angle) {
    return p * exp(Point(0, angle));
}

// Rotate a point P around another point "about" by a given angle (radians)
Point rotateAroundPoint(Point p, double angle, Point about) {
    return rotateAroundOrigin(p - about, angle) + about;
}

// Reflect a point P about a line passing through points p0 and p1
Point reflect(Point p, Point p0, Point p1) {
    Point z = p - p0;
    Point w = p1 - p0;
    return conj(z / w) * w + p0;
}

// Reflect a point around a given mirror direction (alternative approach)
Point reflectAroundDirection(Point v, Point m) {
    return conj(v / m) * m;
}

// Clamp value to range [-1, 1] for safe arccos computation
double fixAngle(double A) {
    if (A > 1) return 1;
    if (A < -1) return -1;
    return A;
}

// Compute the minimum angle between two vectors (in radians)
double angleBetweenVectors(Point a, Point O, Point b) {
    Point v1 = a - O;
    Point v2 = b - O;
    return acos(fixAngle(dotProduct(v1, v2) / (getLength(v1) * getLength(v2))));
}

// Compute the angle ABC (angle at point B) in counterclockwise order
double getAngleABC(Point A, Point B, Point C) {
    double angle = getAngle(getVector(B, C)) - getAngle(getVector(B, A));
    if (angle < 0)
        angle += 2 * PI;
    return angle;
}

int main() {
    cout << fixed << setprecision(1);

    // Define some points
    Point a(10, 10);
    Point mirror1(1, 0);
    Point mirror2(0, 1);

    // Demonstrate reflection around a given mirror direction
    cout << a << " reflected around " << mirror1 << " = " 
         << reflectAroundDirection(a, mirror1) << "\n";
    // Expected: Reflecting (10,10) about (1,0) should invert the y-component.

    cout << a << " reflected around " << mirror2 << " = " 
         << reflectAroundDirection(a, mirror2) << "\n";
    // Expected: Reflecting (10,10) about (0,1) should invert the x-component.

    // Additional demonstrations:
    cout << "Angle of point " << a << " = " << getAngle(a) << " radians\n";
    cout << "Length of vector " << a << " = " << getLength(a) << "\n";
    
    // Rotate point a around the origin by 90 degrees (PI/2 radians)
    Point rotated = rotateAroundOrigin(a, PI / 2);
    cout << a << " rotated by 90 degrees = " << rotated << "\n";
    
    return 0;
}
```

---

## Conclusion

- **Complex Numbers as 2D Points:**  
  Complex numbers naturally represent 2D points and allow for elegant geometric computations.
  
- **Operations:**  
  Basic operations such as dot product, cross product, vector normalization, and angle calculations are easily implemented using complex arithmetic.
  
- **Rotation and Reflection:**  
  Rotation is performed by multiplying by \( e^{i\theta} \), and reflection can be derived using conjugation.
  
- **Practical Use:**  
  These operations form the basis for many computational geometry problems in competitive programming.

This document provides both the mathematical proofs and a working C++ implementation for using complex numbers in 2D geometry. Let me know if you need any further clarifications or modifications!