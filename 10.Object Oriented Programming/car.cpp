#include <bits/stdc++.h>
using namespace std;

class Car {
	//access specifiers = public / private
private:
	float price;
public:
	int model_no;
	char name[20];

	//Constructor
	Car() {
		cout << "Inside Car Constructor" << endl;	//overwriting the automatic constructor
	}
	//Parameterised Constructor
	Car(float p, int m, char *n) {
		price = p;
		model_no = m;
		strcpy(name, n);
	}
	//This is what a copy constrctor looks like but we have to pass by reference
	Car(Car &x) {
		cout << "Copy Constructor" << " ";
		price = x.price;
		model_no = x.model_no;
		strcpy(name, x.name);
	}

	void print() {
		cout << "Name " << name << endl;
		cout << "Model no " << model_no << endl;
		cout << "Price " << price << endl;
	}

	float get_discounted_price(float x) {
		return (price * (100.0 - x)) / 100;
	}

	float apply_discount(float x) {
		price = (price * (100.0 - x)) / 100;
		return price;
	}

	float get_price() {
		return price;
	}

	void set_price(float p) {
		float msp = 111;
		if (p > 0) {
			price = p;
		}
		else {
			price = msp;
		}
	}
	//Destructor
	~Car() {
		cout << "Inside of Destructor of car " << name << endl;
	}
	//own destructor in car_deep_copy.cpp file
};

int main() {

	Car c;
	cout << sizeof(c) << endl;	//it occupies 28 bytes (int- 4 * 2, char- 20)
	cout << sizeof(Car) << endl; // it doesn't occupy any memory but output willbe same as c
	//cause it is just symbolising that if you create a object out of this class it'll occupy 28 bytes
	Car d(222, 114, "Audi");
	d.print();

	Car e(d);	//copy constructor
	e.set_price(456);
	e.print();

	//another way to call copy constructor
	Car f = e;
	f.print();

	//c.price = 100;
	c.set_price(-120);
	c.model_no = 112;
	c.name[0] = 'B';
	c.name[1] = 'M';
	c.name[2] = 'W';
	c.name[3] = '\0';

	//cout << c.name << " Model no: " << c.model_no << " with price $" << c.price << endl;
	c.print();

	/*cout << "Enter the discount amount: ";
	float discount;
	cin >> discount;

	cout << c.get_discounted_price(discount) << endl;

	cout << c.apply_discount(discount) << endl;*/

	return 0;
}