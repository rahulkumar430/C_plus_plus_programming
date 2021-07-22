#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
	int n,key;
	cin>>n;

	int a[1000];

	for( int i=0; i<n; i++){
		cin>> a[i];
	}
	int largest = INT_MIN;
	int smallest = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		// to avoid if else condition you can use max min
		/*
		if(a[i]>largest){
			largest = a[i];

		}
		if (a[i]<smallest)
		{
			 
			smallest = a[i];
		}*/
		largest = max(largest, a[i]);
		smallest = min(smallest, a[i]);
	}
	cout<<"The largest element is :"<<largest<<endl;
	cout<<"The smallest element is :"<<smallest<<endl;
	return 0;
}