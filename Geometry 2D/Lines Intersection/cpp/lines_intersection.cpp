// Solution of UVA 378 problem.
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=5&problem=314
// Short statement: Find intersection of two lines or output if there is no such or it is infinite.

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct pt {
	double x, y;
};

struct line {
	double a, b, c;
	line(pt p1, pt p2) {
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = -a * p1.x - b * p1.y;
	}
};

const double EPS = 1e-9;

double det (double a, double b, double c, double d) {
	return a * d - b * c;
}

bool intersect (line m, line n, pt & res) {
	double zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS)
		return false;
	res.x = - det (m.c, m.b, n.c, n.b) / zn;
	res.y = - det (m.a, m.c, n.a, n.c) / zn;
	return true;
}

bool parallel (line m, line n) {
	return abs (det (m.a, m.b, n.a, n.b)) < EPS;
}

bool equivalent (line m, line n) {
	return abs (det (m.a, m.b, n.a, n.b)) < EPS
		&& abs (det (m.a, m.c, n.a, n.c)) < EPS
		&& abs (det (m.b, m.c, n.b, n.c)) < EPS;
}

void solve(line a, line b) {
	if (equivalent(a, b)) {
		cout << "LINE\n";
		return ;
	}
	if (parallel(a, b)) {
		cout << "NONE\n";
		return ;
	}
	pt res;
	intersect(a, b, res);
	cout.precision(2);
	cout << "POINT " << fixed << res.x << " " << res.y << "\n";
}

int main() {
	int t;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT\n";
	while (t--) {
	    pt p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		line a = line(p1, p2);
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		line b = line(p1, p2);

		solve(a, b);
	}
	cout << "END OF OUTPUT\n";
    return 0;
}
