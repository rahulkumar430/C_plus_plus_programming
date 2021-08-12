#include <bits/stdc++.h>
#include "hashtable.h"
using namespace std;

int main(){

	Hashtable<int> price_menu; 
	price_menu.insert("Burger", 120); 
	price_menu.insert("Pepsi", 20); 
	price_menu.insert("BurgerPizza", 150); 
	price_menu.insert("Noodles", 25); 
	price_menu.insert("Coke", 40); 

	price_menu.print();

	int *price = price_menu.search("Noodles"); 
	if(price==NULL){ 
		cout << "Not found!" <<endl; 
	} 
	else { 
		cout << "Price is " << *price << endl; 
	} 

	price_menu.erase("Coke");

	price_menu.print();


	//Insert
	price_menu["Dosa"] = 60;
	//Update
	price_menu["Dosa"] += 10;
	//Search
	cout << "Price of Dosa ";
	cout << price_menu["Dosa"] << endl;
	return 0;
}