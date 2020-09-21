/*// C++ program to find GCD of two numbers 
#include <iostream> 
using namespace std; 
// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
	// Everything divides 0 
	if (a == 0) 
	return b; 
	if (b == 0) 
	return a; 

	// base case 
	if (a == b) 
		return a; 

	// a is greater 
	if (a > b) 
		return gcd(a-b, b); 
	return gcd(a, b-a); 
} 

// Driver program to test above function 
int main() 
{ 
	int a = 98, b = 56; 
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b); 
	return 0; 
} 
*/

// C++ program to find GCD of two numbers 
#include <iostream> 
using namespace std; 
// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 
	return gcd(b, a % b); 
	
} 

// Driver program to test above function 
int main() 
{ 
	int a = 98, b = 56; 
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b); 
	return 0; 
} 

//to find lcm using gcd
/*
to find LCM = a x b = LCM(a, b) * GCD (a, b)

   LCM(a, b) = (a x b) / GCD(a, b) 
*/