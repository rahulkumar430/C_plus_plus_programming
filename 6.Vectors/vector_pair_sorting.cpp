#include<bits/stdc++.h>
using namespace std;

class Car {
public:
	string car_name;
	int x, y;
	Car() {

	}
	Car(string name, int x, int y) {
		car_name = name;
		this->x = x;
		this-> y = y;
	}
	int dist() {
		return x * x + y * y;
	}
};


bool compare(Car A, Car B) {
	int da = A.dist();
	int db = B.dist();
	if (da == db) {
		return A.car_name.length()  < B.car_name.length();
	}
	return da < db;
}

int main() {

	vector<Car> v;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		string name;
		cin >> name >> x >> y;
		Car temp(name, x, y);
		v.push_back(temp);
	}
	sort(v.begin(), v.end() , compare);

	for (auto it : v) {
		cout << "Car : " << it.car_name << ", " << it.dist() << "Location : " << it.x << ", " << it.y << endl;
	}

	return 0;
}