// Simple Version


#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

typedef complex<double> Point;

// Function to check equality of two floating-point numbers
bool isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

// Function to compute the dot product of two vectors
double dotProduct(Point a, Point b) {
    return (conj(a) * b).real();
}

// Function to compute the cross product of two vectors
double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

// Function to compute the length of a vector
double length(Point a) {
    return hypot(a.real(), a.imag());
}

// Function to find the perpendicular vector
Point perpendicularVector(Point v) {
    return Point(v.imag(), -v.real());
}

// Function to find intersection of two line segments
bool intersectSegments(Point p1, Point p2, Point q1, Point q2, Point &intersection) {
    double d1 = crossProduct(p1 - p2, q1 - q2);
    double d2 = crossProduct(p1 - q1, q1 - q2);
    double d3 = crossProduct(p1 - p2, p1 - q1);

    if (fabs(d1) < EPS) return false; // Parallel or identical lines

    double t1 = d2 / d1;
    double t2 = d3 / d1;

    intersection = p1 + (p2 - p1) * t1;

    return (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1);
}

// Function to find a circle passing through three points
pair<double, Point> findCircle(Point a, Point b, Point c) {
    Point midpoint1 = (a + b) * 0.5;
    Point midpoint2 = (b + c) * 0.5;

    Point direction1 = perpendicularVector(b - a);
    Point direction2 = perpendicularVector(b - c);

    Point end1 = midpoint1 + direction1;
    Point end2 = midpoint2 + direction2;
    
    Point center;
    if (!intersectSegments(midpoint1, end1, midpoint2, end2, center)) {
        return make_pair(-1, Point(0, 0)); // No valid circle if points are collinear
    }

    double radius = length(a - center);
    return make_pair(radius, center);
}

// Function to find intersection of a line and a circle
vector<Point> intersectLineCircle(Point p0, Point p1, Point center, double radius) {
    vector<Point> intersections;
    
    double a = dotProduct(p1 - p0, p1 - p0);
    double b = 2 * dotProduct(p1 - p0, p0 - center);
    double c = dotProduct(p0 - center, p0 - center) - radius * radius;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < -EPS) return intersections; // No intersection

    if (isEqual(discriminant, 0)) discriminant = 0; // Tangent case

    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);

    intersections.push_back(p0 + t1 * (p1 - p0));
    if (!isEqual(discriminant, 0)) {
        intersections.push_back(p0 + t2 * (p1 - p0));
    }

    return intersections;
}

// Function to find the intersection of two circles
vector<Point> intersectCircles(Point c1, double r1, Point c2, double r2) {
    vector<Point> intersections;
    double distance = length(c2 - c1);

    if (isEqual(distance, 0) && isEqual(r1, r2)) {
        return vector<Point>(3, c1); // Infinite intersections (identical circles)
    }

    double angleBetweenCenters = arg(c2 - c1);
    double angleOffset = acos((r1 * r1 + distance * distance - r2 * r2) / (2 * r1 * distance));

    if (isnan(angleOffset)) return intersections; // No intersection

    intersections.push_back(polar(r1, angleBetweenCenters + angleOffset) + c1);
    intersections.push_back(polar(r1, angleBetweenCenters - angleOffset) + c1);

    if (isEqual(intersections[0].real(), intersections[1].real()) &&
        isEqual(intersections[0].imag(), intersections[1].imag())) {
        intersections.pop_back(); // Only one intersection
    }

    return intersections;
}

// Function to find the smallest enclosing circle using Welzl's Algorithm
const int MAX_POINTS = 100000 + 9;
Point points[MAX_POINTS], boundary[3], circleCenter;
double circleRadius;
int totalPoints, boundarySize;

void computeSmallestEnclosingCircle() {
    if (totalPoints == 0 && boundarySize == 2) {
        circleCenter = (boundary[0] + boundary[1]) / 2.0;
        circleRadius = length(boundary[0] - circleCenter);
    } else if (boundarySize == 3) {
        auto circle = findCircle(boundary[0], boundary[1], boundary[2]);
        circleCenter = circle.second;
        circleRadius = circle.first;
    } else if (totalPoints == 0) {
        circleCenter = boundary[0];  
        circleRadius = 0;
    } else {
        totalPoints--;
        computeSmallestEnclosingCircle();

        if (length(points[totalPoints] - circleCenter) > circleRadius) {
            boundary[boundarySize++] = points[totalPoints];
            computeSmallestEnclosingCircle();
            boundarySize--;
        }
        totalPoints++;
    }
}

// Function to print circle intersections
void printIntersections(vector<Point> intersections) {
    if (intersections.empty()) {
        cout << "No Intersection" << endl;
        return;
    }
    for (auto p : intersections) {
        cout << "(" << p.real() << ", " << p.imag() << ")" << endl;
    }
}

int main() {
    // Example: Find a circle through three points
    Point a(0, 0), b(3, 4), c(6, 0);
    auto circle = findCircle(a, b, c);
    cout << "Circle Center: (" << circle.second.real() << ", " << circle.second.imag() << ")" << endl;
    cout << "Radius: " << circle.first << endl;

    // Example: Line-circle intersection
    Point p0(0, 0), p1(5, 5), circleCenter(3, 3);
    double radius = 2;
    cout << "Line-Circle Intersections: " << endl;
    printIntersections(intersectLineCircle(p0, p1, circleCenter, radius));

    // Example: Circle-circle intersection
    Point c1(0, 0), c2(4, 0);
    double r1 = 3, r2 = 3;
    cout << "Circle-Circle Intersections: " << endl;
    printIntersections(intersectCircles(c1, r1, c2, r2));

    return 0;
}




// Mustafa Saad Version


// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
// may be see https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
pair<double, point> findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1+pv1, end2 = m2+pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair( length(a-center), center );  
}



// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C), 
           c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
	    if( dcmp(f, 0) == 0)	f = 0;
	    double t1 =(-b + sqrt(f))/(2*a);
	    double t2 =(-b - sqrt(f))/(2*a);
	    v.push_back( p0 + t1*(p1-p0) );
	    if( dcmp(f, 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  // Handle infinity case first: same center/radius and r > 0
  if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0; // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if(dcmp(dp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}

int intersectCircleCircle_TEST() {
  print(intersectCircleCircle(point(-1.5,-1.5), 0.5, point(1.5,1.5), 0.5));   // no intersection far

  print(intersectCircleCircle(point(0, 0), 5, point(9, 0), 1));   // no intersection far
  print(intersectCircleCircle(point(0, 0), 5, point(0, 0), 1));   // no intersection nested same center
  print(intersectCircleCircle(point(0, 0), 5, point(1, 0), 1));   // no intersection nested

  print(intersectCircleCircle(point(0, 0), 5, point(6, 0), 1));   // 1 intersection: (5,0) external
  print(intersectCircleCircle(point(0, 0), 5, point(4, 0), 1));   // 1 intersection: (5,0) internal
  print(intersectCircleCircle(point(0, 0), 5, point(5, 0), 0));   // 1 intersection: (5,0) point on circle
  print(intersectCircleCircle(point(5, 0), 0, point(5, 0), 0));   // 1 intersection: (5,0) 2 same points

  print(intersectCircleCircle(point(0, 0), 5, point(5, 0), 1));   // 2 intersection: ~(5,1) (5,-1)

  print(intersectCircleCircle(point(0, 0), 5, point(0, 0), 5));   // infinity intersections

  // Full correct testing should consider also swapping these parameters

  return 0;
}




const int MAX = 100000+9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs;	// ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);		rs = 0;
void MEC() {
	if(ps == 0 && rs == 2) {
		cen = (r[0]+r[1])/2.0;
		rad = length(r[0]-cen);
	}
	else if(rs == 3) {
		pair<double, point> p = findCircle(r[0], r[1], r[2]);
		cen = p.second;
		rad = p.first;
	}
	else if(ps == 0) {
		cen = r[0];	// sometime be garbage, but will not affect
		rad = 0;
	}
	else {
		ps--;
		MEC();

		if(length(pnts[ps]-cen) > rad) {
			r[rs++] = pnts[ps];
			MEC();
			rs--;
		}

		ps++;
	}
}

