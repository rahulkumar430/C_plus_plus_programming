#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		long long int x, k, n;
		cin >> n >> k;
		/*x = pow(10, (log10(n) / k));
		cout << x;*/


	}

	return 0;
}

/*

// BINARY SEARCH approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate x raised 
// to the power y in O(logn) 
int power(int x, unsigned int y) 
{ 
	int temp; 
	if (y == 0) 
		return 1; 
	temp = power(x, y / 2); 
	if (y % 2 == 0) 
		return temp * temp; 
	else
		return x * temp * temp; 
} 

// Function to find the Kth 
// root of the number N using BS 
int nthRootSearch(int low, int high, 
				int N, int K) 
{ 

	// If the range is still valid 
	if (low <= high) { 

		// Find the mid-value of range 
		int mid = (low + high) / 2; 

		// Base Case 
		if ((power(mid, K) <= N) 
			&& (power(mid + 1, K) > N)) { 
			return mid; 
		} 

		// Condition to check if the 
		// left search space is useless 
		else if (power(mid, K) < N) { 
			return nthRootSearch(mid + 1, 
								high, N, K); 
		} 
		else { 
			return nthRootSearch(low, 
								mid - 1, 
								N, K); 
		} 
	} 
	return low; 
} 

// Driver Code 
int main() 
{ 

	// Given N and K 
	int N = 16, K = 4; 

	// Function Call 
	cout << nthRootSearch(0, N, N, K) 
		<< endl; 
	return 0; 
} 


*/

/*

according to newton’s method
x(K+1) = x(K) – f(x) / f’(x)        
here    f(x)  = x^(N) – A
so    f’(x) = N*x^(N - 1)
and     x(K) denoted the value of x at Kth iteration
putting the values and simplifying we get,
x(K + 1) = (1 / N) * ((N - 1) * x(K) + A / x(K) ^ (N - 1))


// C++ program to calculate Nth root of a number 
#include <bits/stdc++.h> 
using namespace std; 

// method returns Nth power of A 
double nthRoot(int A, int N) 
{ 
	// intially guessing a random number between 
	// 0 and 9 
	double xPre = rand() % 10; 

	// smaller eps, denotes more accuracy 
	double eps = 1e-3; 

	// initializing difference between two 
	// roots by INT_MAX 
	double delX = INT_MAX; 

	// xK denotes current value of x 
	double xK; 

	// loop untill we reach desired accuracy 
	while (delX > eps) 
	{ 
		// calculating current value from previous 
		// value by newton's method 
		xK = ((N - 1.0) * xPre + 
			(double)A/pow(xPre, N-1)) / (double)N; 
		delX = abs(xK - xPre); 
		xPre = xK; 
	} 

	return xK; 
} 

// Driver code to test above methods 
int main() 
{ 
	int N = 4; 
	int A = 81; 

	double nthRootValue = nthRoot(A, N); 
	cout << "Nth root is " << nthRootValue << endl; 

	/* 
		double Acalc = pow(nthRootValue, N); 
		cout << "Error in difference of powers " 
			<< abs(A - Acalc) << endl; 
	*/

//	return 0; 
// }
*/