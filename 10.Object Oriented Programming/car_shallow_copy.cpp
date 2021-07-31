#include <bits/stdc++.h>
using namespace std;

class Car {
private:
	float price;
public:
	int model_no;
	char *name;
	Car() {
		name = NULL;
	}
	Car(float p, int m, char *n) {
		price = p;
		model_no = m;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	void set_price(float p) {
		price = p;
	}
	void print() {
		cout << "Name " << name << endl;
		cout << "Model no " << model_no << endl;
		cout << "Price " << price << endl;
	}
};

int main() {

	Car c(222, 114, "BMW");
	Car d(c);	//copy constructor

	d.set_price(456);
	d.name[0] = 'A';	//here comes the problem of shallow copy cause both c and d points to the same dynamic array
	//so by changing any of one will change the both
	//for which we need build our own copy constructor to deep copy
	c.print();
	d.print();

	return 0;
}