/*
--------------	 \
Count Rctangles   \
------------------ \
Given N cartesian points, find the numbere of axis parallel rectangles that can be formed by them.

points = {{0,0},{0,1},{1,1},{1,0},{2,1},{2,0},{3,1},{3,0}}
*/
#include <bits/stdc++.h>
using namespace std;

class Point {
public:
	int x, y;
	Point() {

	}
	Point(int x, int y) {
		this-> x = x;
		this-> y = y;
	}
};

class Compare {
public:
	bool operator()(Point p1, Point p2) {
		if (p1.x == p2.x) {
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};

int count_rects(vector<Point> coords) {
	int n = coords.size();
	//insert the set
	set<Point, Compare> s;
	for (auto p : coords) {
		s.insert(p);
	}

	//run 2 loops
	int ans = 0;

	for (auto it = s.begin(); it != prev(s.end()); it++) {
		for (auto jt = next(it); jt != s.end(); jt++) {
			Point p1 = *it;
			Point p2 = *jt;

			if (p2.x == p1.x or p2.y == p1.y) {
				continue;
			}
			Point p3(p2.x, p1.y);
			Point p4(p1.x, p2.y);
			if (s.find(p3) != s.end() and s.find(p4) != s.end()) {
				ans++;
			}
		}
	}

	return ans / 2;
}

int main() {

	int m;
	cin >> m;

	vector<Point> coords;

	while (m--) {
		int x, y;
		cin >> x >> y;
		Point p(x, y);
		coords.push_back(p);
	}

	cout << count_rects(coords) << endl;
	return 0;
}
//input example
/*
8
0 0
0 1
1 1
1 0
2 1
2 0
3 0
3 1
*/