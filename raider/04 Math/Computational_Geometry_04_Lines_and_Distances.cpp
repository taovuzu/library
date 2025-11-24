// Simple Version


#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;  // Small value for floating point comparisons

typedef complex<double> Point;

// Function to compute the angle of a complex number
double getAngle(Point a) {
    return atan2(a.imag(), a.real());
}

// Function to get the vector between two points
Point getVector(Point a, Point b) {
    return b - a;
}

// Function to compute dot product (used to check perpendicularity)
double dotProduct(Point a, Point b) {
    return (conj(a) * b).real();
}

// Function to compute cross product (used to check parallel lines)
double crossProduct(Point a, Point b) {
    return (conj(a) * b).imag();
}

// Function to compute the length of a vector
double getLength(Point a) {
    return hypot(a.real(), a.imag());
}

// Function to normalize a vector
Point normalize(Point a) {
    return a / getLength(a);
}

// Function to rotate a point around the origin by an angle
Point rotateAroundOrigin(Point p, double angle) {
    return p * exp(Point(0, angle));
}

// Function to rotate a point around another point
Point rotateAroundPoint(Point p, double angle, Point about) {
    return rotateAroundOrigin(p - about, angle) + about;
}

// Function to reflect a point around another point
Point reflect(Point p, Point p0, Point p1) {
    Point z = p - p0, w = p1 - p0;
    return conj(z / w) * w + p0;
}

// Function to check if three points are collinear
bool isCollinear(Point a, Point b, Point c) {
    return fabs(crossProduct(b - a, c - a)) < EPS;
}

// Function to check if a point lies on a ray
bool isPointOnRay(Point p0, Point p1, Point p2) {
    if (getLength(p2 - p0) < EPS) return true;
    return abs(normalize(p1 - p0) - normalize(p2 - p0)) < EPS;
}

// Function to check if a point lies on a line segment
bool isPointOnSegment(Point a, Point b, Point c) {
    double totalLength = getLength(a - b);
    double part1 = getLength(a - c);
    double part2 = getLength(b - c);
    return fabs(totalLength - (part1 + part2)) < EPS;
}

// Function to compute distance from a point to a line
double distanceToLine(Point p0, Point p1, Point p2) {
    return fabs(crossProduct(p1 - p0, p2 - p0) / getLength(p0 - p1));
}

// Function to compute distance from a point to a line segment
double distanceToSegment(Point p0, Point p1, Point p2) {
    double d1, d2;
    Point v1 = p1 - p0, v2 = p2 - p0;
    
    if ((d1 = dotProduct(v1, v2)) <= 0) return getLength(p2 - p0);
    if ((d2 = dotProduct(v1, v1)) <= d1) return getLength(p2 - p1);
    
    double t = d1 / d2;
    return getLength(p2 - (p0 + v1 * t));
}

// Main function to demonstrate reflections
int main() {
    Point a(10, 10);
    Point m1(1, 0);
    Point m2(0, 1);

    cout << a << " reflected around " << m1 << " = " << reflect(a, Point(0, 0), m1) << "\n";
    cout << a << " reflected around " << m2 << " = " << reflect(a, Point(0, 0), m2) << "\n";

    return 0;
}



// Mustafa Saad Version


#include <iostream>
#include <cmath>
#include <complex>
#include <bits/stdc++.h>
using namespace std;

const double PI  = acos(-1.0);

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}





bool isCollinear(point a, point b, point c) {	
	return fabs( cp(b-a, c-a) ) < EPS;	
} 

bool isPointOnRay(point p0, point p1, point p2) {
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

bool isPointOnRay(point a, point b, point c) {	// not tested?
    if(!isCollinear(a, b, c))
    	return false;
    return dcmp(dp(b-a, c-a), 0) == 1;
}

bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a-b), ac = length(a-c), cb = length(b-c);
	return dcmp(acb-(ac+cb), 0) == 0;
}





double distToLine( point p0, point p1, point p2 ) {
	return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}




//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}
