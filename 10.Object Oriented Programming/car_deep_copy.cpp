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
	//deep copy
	Car(Car &x) {
		price = x.price;
		model_no = x.model_no;
		//creating a diffrent dynamic array
		name = new char[strlen(x.name) + 1];
		strcpy (name, x.name);
	}
	//our own copy assignment operator with deep copy
	void operator=(Car &x) {
		price = x.price;
		model_no = x.model_no;
		//creating a diffrent dynamic array
		name = new char[strlen(x.name) + 1];
		strcpy (name, x.name);
	}

	void set_price(float p) {
		price = p;
	}
	void print() {
		cout << "Name " << name << endl;
		cout << "Model no " << model_no << endl;
		cout << "Price " << price << endl;
	}

	//Our own Destructor
	~Car() {
		cout << "Destroying car " << name << endl;
		if (name != NULL) {
			delete [] name;
		}
	}
};

int main() {
	//static car object
	Car c(222, 114, "BMW");
	//Car d(c);	//copy constructor
	Car d;
	d = c;	//It won't call copy constructor but will call copy assignment operator

	d.set_price(456);
	d.name[0] = 'A';

	c.print();
	d.print();

	//dynamically created car object
	Car *e = new Car(10,20,"Ferrari");
	e->print();
	delete e;

	//(*e).print();

	return 0;
}