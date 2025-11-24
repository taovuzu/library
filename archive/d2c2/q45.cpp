#include <bits/stdc++.h>

using namespace std;

#define int long long

const double PI = acos(-1.0);
const double EPS = 1e-9;
const double EPS1 = 1e-5;

typedef complex<double> Point;

int dcmp(double x, double y) {
    if (fabs(x - y) < EPS) return 0;
    return (x < y) ? -1 : 1;
}

// Compute the length of a vector
double getLength(Point a) {
    return hypot(a.imag(), a.real());
}

vector<Point> circleIntersections(Point C1, double r1, Point C2, double r2) {
    double d = abs(C2 - C1);
    if (dcmp(d, r1 + r2) > 0 || dcmp(d, fabs(r1 - r2)) < 0) return {};
    if (dcmp(d, 0) == 0 && dcmp(r1, r2) == 0) return {}; // Identical circles case

    double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    double h = sqrt(max(0.0, r1 * r1 - a * a));

    Point P = C1 + a * (C2 - C1) / d;
    Point offset = Point(0, 1) * h * (C2 - C1) / d; 

    if (dcmp(h, 0) == 0) return {P};
    return {P + offset, P - offset};
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double x, y, r1, r2;

    while (cin >> x >> y >> r1) {
        Point p0(x, y);

        if (!(cin >> x >> y >> r2)) break;
        Point p1(x, y);

        double dis = getLength(p1 - p0);

        if (dcmp(dis, 0) == 0 && dcmp(r1, r2) == 0) {
            cout << "THE CIRCLES ARE THE SAME" << "\n";
            continue;
        }

        if (dcmp(dis, r1 + r2) > 0 || dcmp(dis, fabs(r1 - r2)) < 0) {
            cout << "NO INTERSECTION" << "\n";
            continue;
        }

        vector<Point> ans = circleIntersections(p0, r1, p1, r2);
        sort(ans.begin(), ans.end(), [](Point xx, Point yy) {
            if (dcmp(xx.real(), yy.real()) == 0) return xx.imag() < yy.imag();
            return xx.real() < yy.real();
        });

        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) cout << " ";
            cout << fixed << setprecision(3) << "(" << ans[i].real() + EPS1 << "," 
                 << ans[i].imag() + EPS1 << ")";
        }
        cout << "\n";
    }

    return 0;
}
