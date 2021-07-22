#include <bits/stdc++.h>

using namespace std;

void countSort(int array[], int size) {
	// The size of count must be at least the (max+1) but
	// we cannot assign declare it as int count(max+1) in C++ as
	// it does not support dynamic memory allocation.
	// So, its size is provided statically.
	int output[1000];
	int count[1000];
	int max = array[0];

	// Find the largest element of the array
	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}

	// Initialize count array with all zeros.
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Store the count of each element
	for (int i = 0; i < size; i++) {
		count[array[i]]++;
	}

	// Store the cummulative count of each array
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (int i = size - 1; i >= 0; i--) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	// Copy the sorted elements into original array
	for (int i = 0; i < size; i++) {
		array[i] = output[i];
	}
}

// Function to print an array
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

// Driver code
int main() {

	int n;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	countSort(array, n);
	printArray(array, n);
	/*
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int M=amax(a,n);

	//initialise all elements by 0
	int freq[M+1]={0};

	for(int i=0;i<n;i++) freq[a[i]]+=1;
	for(int i=0;i<=M;i++){
	    while(freq[i]!=0){
	        cout<<i<<" ";
	        freq[i]--;
	    }
	}
	*/
}