# **Understanding Computational Geometry with Circles – In Simple Terms**
---

## **1. What Are We Trying to Solve?**
The code covers several important circle-related computations, such as:
1. **Finding a circle that passes through three points.**
2. **Finding the intersection of a line and a circle.**
3. **Finding the intersection of two circles.**
4. **Finding the smallest circle that encloses all given points.**

Each of these problems is useful in **competitive programming**, geometry applications, and game development.

---

## **2. Finding a Circle Through 3 Points**
### **Problem:**
- Given three points, we need to find a **unique circle** that passes through all of them.
- If the points are **collinear** (in a straight line), no such circle exists.

### **How It Works:**
1. **Two points have infinitely many possible circles** that pass through them.
2. **Three non-collinear points define a unique circle**.
3. **To find the circle**, we:
   - Compute the **midpoints** of two line segments.
   - Find **perpendicular bisectors** to these segments.
   - The **intersection** of these bisectors gives the **circle center**.
   - The **radius** is the distance from the center to any of the three points.

### **Code Explanation:**
```cpp
pair<double, point> findCircle(point a, point b, point c) {
    // Find the midpoints of two sides
    point m1 = (b + a) * 0.5;
    point m2 = (b + c) * 0.5;

    // Find direction vectors of sides
    point v1 = b - a;
    point v2 = b - c;

    // Find perpendicular vectors
    point pv1 = point(v1.imag(), -v1.real());
    point pv2 = point(v2.imag(), -v2.real());

    // Compute two end points of the perpendicular bisectors
    point end1 = m1 + pv1;
    point end2 = m2 + pv2;

    // Find intersection of these bisectors
    point center;
    intersectSegments(m1, end1, m2, end2, center);

    return make_pair(length(a - center), center); // Return radius and center
}
```

### **Key Takeaways:**
✅ Uses perpendicular bisectors to find the circle center.  
✅ Works only if the points are **not collinear**.  
✅ The intersection of bisectors gives the **unique center**.  

---

## **3. Finding the Intersection of a Line and a Circle**
### **Problem:**
- Given a **circle (center C, radius r)** and a **line (P0 to P1)**, find their intersection points.
- A line can **touch a circle at 1 point (tangent), cut at 2 points (secant), or miss it entirely**.

---

### **1. Parametric Equation of the Line**
A line passing through two points \( p_0 \) and \( p_1 \) can be parameterized as:
\[
P(t) = p_0 + t \cdot (p_1 - p_0)
\]
where \( t \) is a real number.

### **2. Circle Equation**
A circle centered at \( C \) with radius \( r \) is defined by:
\[
(x - C_x)^2 + (y - C_y)^2 = r^2
\]

### **3. Substituting Line Equation into Circle Equation**
We substitute \( P(t) \) into the circle equation:

\[
\left( (p_{0x} + t (p_{1x} - p_{0x})) - C_x \right)^2 + \left( (p_{0y} + t (p_{1y} - p_{0y})) - C_y \right)^2 = r^2
\]

Expanding and simplifying, we get a **quadratic equation** of the form:

\[
a t^2 + b t + c = 0
\]

where:
- \( a = (p_1 - p_0) \cdot (p_1 - p_0) \) (dot product of the direction vector with itself)
- \( b = 2 \cdot (p_1 - p_0) \cdot (p_0 - C) \) (twice the dot product of the direction vector and vector from the circle center to p0)
- \( c = (p_0 - C) \cdot (p_0 - C) - r^2 \) (distance squared from \( p_0 \) to \( C \), minus the squared radius)

This quadratic equation determines the intersection points.

---

### **Code Explanation:**
```cpp
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dotProduct(p1 - p0, p1 - p0);
    double b = 2 * dotProduct(p1 - p0, p0 - C);
    double c = dotProduct(p0 - C, p0 - C) - r * r;

    double discriminant = b * b - 4 * a * c;
    vector<point> intersections;

    if (dcmp(discriminant, 0) >= 0) { // If the discriminant is non-negative
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);

        intersections.push_back(p0 + t1 * (p1 - p0));
        if (dcmp(discriminant, 0) != 0)
            intersections.push_back(p0 + t2 * (p1 - p0));
    }
    return intersections;
}
```

## **Code Breakdown**
### **1. Compute Coefficients**
```cpp
double a = dotProduct(p1 - p0, p1 - p0);
double b = 2 * dotProduct(p1 - p0, p0 - C);
double c = dotProduct(p0 - C, p0 - C) - r * r;
```
- Computes the coefficients of the quadratic equation.

### **2. Compute Discriminant**
```cpp
double discriminant = b * b - 4 * a * c;
```
- The discriminant determines the nature of the intersection:
  - **If discriminant < 0** → No real solutions (no intersection).
  - **If discriminant = 0** → One solution (line is tangent to the circle).
  - **If discriminant > 0** → Two solutions (two intersection points).

### **3. Check for Real Solutions**
```cpp
if (dcmp(discriminant, 0) >= 0) { // If the discriminant is non-negative
```
- `dcmp(discriminant, 0)` is a function used for floating-point comparison. It likely:
  - Returns `0` if the values are almost equal.
  - Returns `1` if `discriminant > 0`.
  - Returns `-1` if `discriminant < 0`.

### **4. Compute Intersection Points**
```cpp
double t1 = (-b + sqrt(discriminant)) / (2 * a);
double t2 = (-b - sqrt(discriminant)) / (2 * a);
```
- Uses the quadratic formula to solve for \( t_1 \) and \( t_2 \).

```cpp
intersections.push_back(p0 + t1 * (p1 - p0));
```
- Computes the first intersection point using \( t_1 \).

```cpp
if (dcmp(discriminant, 0) != 0)
    intersections.push_back(p0 + t2 * (p1 - p0));
```
- If discriminant is **not exactly zero**, we have a second intersection point.

---

### **Complexity**
- The function runs in \( O(1) \) time because it performs a constant number of arithmetic operations and vector operations.

### **Edge Cases**
- **No intersection**: When the discriminant is negative.
- **Tangent case**: When the discriminant is exactly zero.
- **Degenerate cases**:
  - If the line is actually a single point, it should be handled separately.

### **Key Takeaways:**
✅ Uses **quadratic equations** to find intersection points.  
✅ **Discriminant (`b² - 4ac`)** determines the number of intersections.  
✅ Returns **0, 1, or 2 points**, depending on how the line interacts with the circle.

---
# **Finding the Intersection of Two Circles**

## **Problem Statement:**
Given two circles with centers \( C_1, C_2 \) and radii \( r_1, r_2 \), find their intersection points.

## **Possible Cases:**
1. **No Intersection**:  
   - The circles are too far apart \( d > r_1 + r_2 \).  
   - One circle is completely inside the other without touching \( d < |r_1 - r_2| \).  
2. **One Intersection (Tangent Circles)**:  
   - Externally tangent \( d = r_1 + r_2 \).  
   - Internally tangent \( d = |r_1 - r_2| \).  
3. **Two Intersections**:  
   - The circles overlap at two points \( |r_1 - r_2| < d < r_1 + r_2 \).  
4. **Infinite Intersections**:  
   - The circles are identical \( C_1 = C_2 \) and \( r_1 = r_2 \).  

---

## **Solution Approach Using Complex Numbers:**
1. Represent points as **complex numbers**:  
   - \( C_1 = x_1 + iy_1 \), \( C_2 = x_2 + iy_2 \).  
2. Compute the Euclidean distance \( d = |C_2 - C_1| \).  
3. If two intersections exist, compute the intersection points using vector projection and trigonometry.  

---

## **C++ Code Using Complex Numbers:**
```cpp
#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;
const double EPS = 1e-9;

int dcmp(double x, double y) {
    if (fabs(x - y) < EPS) return 0;
    return (x < y) ? -1 : 1;
}

vector<Point> circleIntersections(Point C1, double r1, Point C2, double r2) {
    double d = abs(C2 - C1); // Distance between centers
    if (dcmp(d, r1 + r2) > 0 || dcmp(d, fabs(r1 - r2)) < 0) return {}; // No intersection

    double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    double h = sqrt(max(0.0, r1 * r1 - a * a)); // Height from center line to intersection points

    Point P = C1 + a * (C2 - C1) / d; // Base point on center line
    Point offset = Point(0, 1) * h * (C2 - C1) / d; // Perpendicular offset

    if (dcmp(h, 0) == 0) return {P}; // One intersection (tangent)
    return {P + offset, P - offset}; // Two intersections
}

int main() {
    Point C1(0, 0), C2(4, 0);
    double r1 = 3, r2 = 3;

    vector<Point> result = circleIntersections(C1, r1, C2, r2);
    for (auto p : result)
        cout << fixed << setprecision(6) << p.real() << " " << p.imag() << endl;

    return 0;
}
```

---

## **Key Takeaways:**
✅ Uses **complex numbers** for point representation.  
✅ Handles all cases (no intersection, tangent, two intersections).  
✅ Uses vector projection for calculating intersection points.  
✅ **Efficient and numerically stable**.  

Let me know if you need modifications! 🚀
# **Finding the Intersection of Two Circles**

## **Problem Statement:**
Given two circles with centers \( C_1, C_2 \) and radii \( r_1, r_2 \), find their intersection points.

## **Possible Cases:**
1. **No Intersection**:  
   - The circles are too far apart \( d > r_1 + r_2 \).  
   - One circle is completely inside the other without touching \( d < |r_1 - r_2| \).  
2. **One Intersection (Tangent Circles)**:  
   - Externally tangent \( d = r_1 + r_2 \).  
   - Internally tangent \( d = |r_1 - r_2| \).  
3. **Two Intersections**:  
   - The circles overlap at two points \( |r_1 - r_2| < d < r_1 + r_2 \).  
4. **Infinite Intersections**:  
   - The circles are identical \( C_1 = C_2 \) and \( r_1 = r_2 \).  

---

## **Solution Approach Using Complex Numbers:**
1. Represent points as **complex numbers**:  
   - \( C_1 = x_1 + iy_1 \), \( C_2 = x_2 + iy_2 \).  
2. Compute the Euclidean distance \( d = |C_2 - C_1| \).  
3. If two intersections exist, compute the intersection points using vector projection and trigonometry.  

---

## **C++ Code Using Complex Numbers:**
```cpp
#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;
const double EPS = 1e-9;

int dcmp(double x, double y) {
    if (fabs(x - y) < EPS) return 0;
    return (x < y) ? -1 : 1;
}

vector<Point> circleIntersections(Point C1, double r1, Point C2, double r2) {
    double d = abs(C2 - C1); // Distance between centers
    if (dcmp(d, r1 + r2) > 0 || dcmp(d, fabs(r1 - r2)) < 0) return {}; // No intersection

    double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    double h = sqrt(max(0.0, r1 * r1 - a * a)); // Height from center line to intersection points

    Point P = C1 + a * (C2 - C1) / d; // Base point on center line
    Point offset = Point(0, 1) * h * (C2 - C1) / d; // Perpendicular offset

    if (dcmp(h, 0) == 0) return {P}; // One intersection (tangent)
    return {P + offset, P - offset}; // Two intersections
}

int main() {
    Point C1(0, 0), C2(4, 0);
    double r1 = 3, r2 = 3;

    vector<Point> result = circleIntersections(C1, r1, C2, r2);
    for (auto p : result)
        cout << fixed << setprecision(6) << p.real() << " " << p.imag() << endl;

    return 0;
}
```

---

## **Key Takeaways:**
✅ Uses **complex numbers** for point representation.  
✅ Handles all cases (no intersection, tangent, two intersections).  
✅ Uses vector projection for calculating intersection points.  
✅ **Efficient and numerically stable**.  

---

# **Finding the Smallest Enclosing Circle**

## **Problem Statement:**
Given **N points**, find the **smallest circle** that contains all of them.

## **How It Works:**
1. **Base Cases**:
   - If **0 points**, return an empty circle.
   - If **1 point**, return a circle of radius 0.
   - If **2 points**, return a circle with these as the diameter.
   - If **3 points**, compute the circle passing through them.

2. **Welzl’s Algorithm** (Recursive O(N) approach):
   - Shuffle the points randomly.
   - Add points one by one.
   - If a point is **outside the current circle**, recompute it using boundary points.

---

## **C++ Code Using Complex Numbers:**
```cpp
#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;
struct Circle {
    Point c;
    double r;
};

Circle getCircleFromTwoPoints(Point A, Point B) {
    Point center = (A + B) / 2.0;
    double radius = abs(A - B) / 2.0;
    return {center, radius};
}

Circle getCircleFromThreePoints(Point A, Point B, Point C) {
    Point D = (A + B) / 2.0;
    Point E = (B + C) / 2.0;
    Point dir1 = (B - A) * Point(0, 1);
    Point dir2 = (C - B) * Point(0, 1);
    double t = imag((E - D) / dir1) / imag(dir2 / dir1);
    Point center = E + t * dir2;
    double radius = abs(center - A);
    return {center, radius};
}

circle welzl(const vector<point> &P, int n, vector<point> R = {}) {
    if (n == 0 || R.size() == 3) {
        if (R.empty())      return {{0,0}, 0};
        if (R.size() == 1)  return {R[0], 0};
        if (R.size() == 2)  return getCircleFromTwoPoints(R[0], R[1]);
        return getCircleFromThreePoints(R[0], R[1], R[2]);
    }

    point p = P[n-1];
    circle d = welzl(P, n-1, R);
    if (abs(p - d.c) <= d.r + EPS) {
        return d;
    }
    R.push_back(p);
    return welzl(P, n-1, R);
}

int main() {
    vector<Point> points = {{0, 0}, {4, 0}, {2, 3}, {3, 2}};
    random_shuffle(points.begin(), points.end());
    Circle result = welzl(points);
    cout << fixed << setprecision(6) << result.c.real() << " " << result.c.imag() << " " << result.r << endl;
    return 0;
}
```

---

## **Key Takeaways:**
✅ Uses **recursive approach** for efficiency.  
✅ Only keeps **necessary boundary points**.  
✅ Guarantees **minimal enclosing circle** in **O(N)** time.

