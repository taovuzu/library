# Computational Geometry: Points and Vectors

---

## 1. Coordinate Systems

### 1.1. Cartesian Coordinate System

- **Definition:**  
  In the Cartesian coordinate system, every point in 2D space is defined by an ordered pair \((x, y)\).  
- **Representation:**  
  Points, lines, and vectors are expressed using \(x\) and \(y\) coordinates.

### 1.2. Polar Coordinate System

- **Definition:**  
  A point \(P\) is represented by the pair \((r, \theta)\), where:  
  - \(r\) is the distance from the point to the origin \(O\).  
  - \(\theta\) is the angle between the ray \(OP\) and the polar axis (typically the positive \(x\)-axis).

### 1.3. Cartesian ⇔ Polar Conversions

- **From Cartesian to Polar:**
  $$
  r = \sqrt{x^2 + y^2}, \quad \theta = \arctan\left(\frac{y}{x}\right)
  $$
- **From Polar to Cartesian:**
  $$
  x = r \cos\theta, \quad y = r \sin\theta
  $$

---

## 2. Vectors

### 2.1. Definition

- **Vector:**  
  A vector is an entity with both **magnitude** (length) and **direction**.  
  For example, the vector from point \(a = (1,3)\) to \(b = (5,1)\) is:
  $$
  \mathbf{v} = b - a = (5-1,\, 1-3) = (4, -2)
  $$
- **Magnitude (Norm):**
  $$
  \|\mathbf{v}\| = \sqrt{4^2 + (-2)^2} = \sqrt{16 + 4} = \sqrt{20}
  $$

### 2.2. Linear Independence

- **Definition:**  
  A set of vectors is linearly dependent if one of the vectors can be expressed as a linear combination of the others.  
  For example, if \(u = (1,3)\) and \(v = (2,6)\), then \(v = 2u\) (they are dependent).

### 2.3. Perpendicular and Orthogonal Vectors

- **Perpendicular Vectors:**  
  Two vectors are perpendicular if the angle between them is \(90^\circ\).  
  This is equivalent to their dot product being zero.
- **Orthogonal Vectors:**  
  A set of vectors is orthogonal if every pair of distinct vectors in the set is perpendicular.

### 2.4. Normal Vector

- **Definition:**  
  A normal vector to a surface or line is a vector that is perpendicular to that surface or line at a given point.

---

## 3. Vector Operations

### 3.1. Vector Addition and Subtraction

- **Addition:**  
  For vectors \(a = (a_1, a_2)\) and \(b = (b_1, b_2)\):
  $$
  a + b = (a_1+b_1,\, a_2+b_2)
  $$
- **Subtraction:**  
  $$
  a - b = (a_1-b_1,\, a_2-b_2)
  $$

### 3.2. Dot (Scalar/Inner) Product

- **Definition:**  
  The dot product of two vectors \(a = (a_1, a_2)\) and \(b = (b_1, b_2)\) is:
  $$
  a \cdot b = a_1 b_1 + a_2 b_2
  $$
- **Geometric Interpretation:**  
  It equals the product of the magnitudes and the cosine of the angle between them:
  $$
  a \cdot b = \|a\|\,\|b\|\cos\theta
  $$
  Thus, if \(a\) and \(b\) are orthogonal, then \(a \cdot b = 0\).

### 3.3. Cross (Vector) Product

- **Definition (2D Interpretation):**  
  In 2D, the cross product is defined as the scalar:
  $$
  a \times b = a_1 b_2 - a_2 b_1
  $$
- **Geometric Interpretation:**  
  The magnitude \(|a \times b|\) represents the area of the parallelogram with sides \(a\) and \(b\). For a triangle, the area is half of this value.

### 3.4. Standard Basis

- **Definition:**  
  The standard basis in 2D consists of the unit vectors:
  $$
  \mathbf{i} = (1, 0) \quad \text{and} \quad \mathbf{j} = (0, 1)
  $$

---

## 4. Geometric Operations and Euclidean Transformations

### 4.1. Translation

- **Operation:**  
  Translating a point \((x, y)\) by a vector \((h, k)\) results in:
  $$
  (x', y') = (x+h,\, y+k)
  $$

### 4.2. Rotation

- **About the Origin:**  
  To rotate a point \((x, y)\) by an angle \(a\) (in radians) about the origin:
  $$
  x' = x\cos a - y\sin a, \quad y' = x\sin a + y\cos a
  $$
- **Rotation in Matrix Form:**  
  $$
  \begin{bmatrix} x' \\ y' \end{bmatrix} =
  \begin{bmatrix} \cos a & -\sin a \\ \sin a & \cos a \end{bmatrix}
  \begin{bmatrix} x \\ y \end{bmatrix}
  $$

### 4.3. Reflection

- **Reflection Across a Line Through the Origin:**  
  For a line making an angle \(\theta\) with the \(x\)-axis, reflecting a point \((x, y)\) across that line can be computed by transforming the coordinates. One common formula for reflection is:
  $$
  \begin{aligned}
  x' &= x\cos2\theta + y\sin2\theta, \\
  y' &= x\sin2\theta - y\cos2\theta.
  \end{aligned}
  $$
- **Reflection in Matrix Form:**  
  A reflection matrix for a line through the origin with angle \(\theta\) is:
  $$
  R = \begin{bmatrix}
  \cos 2\theta & \sin 2\theta \\
  \sin 2\theta & -\cos 2\theta
  \end{bmatrix}
  $$
  Applying \(R\) to a point \((x, y)\) gives its reflected coordinates.

### 4.4. Composition of Transformations

- **Combining Transformations:**  
  Multiple Euclidean transformations (such as rotation followed by translation) can be composed by multiplying their corresponding transformation matrices. The order of operations is important.

---

## 5. Conclusion

- **Coordinate Systems:**  
  Cartesian and polar representations provide two complementary ways to describe points in the plane. Conversion formulas link these systems.
- **Vectors:**  
  Vectors represent both direction and magnitude, and they are essential for describing motion, forces, and geometric transformations.  
- **Vector Operations:**  
  Addition, subtraction, dot product, and cross product are fundamental operations with both algebraic and geometric interpretations.
- **Euclidean Transformations:**  
  Translations, rotations, and reflections are key to manipulating geometric objects without altering their intrinsic properties (lengths and angles). Their composition via matrices allows for complex transformations.

This document serves as an introduction to points and vectors in computational geometry and provides the foundational concepts required for more advanced topics and competitive programming problems.

---

Feel free to use, modify, or extend this document as needed for your studies or programming challenges!