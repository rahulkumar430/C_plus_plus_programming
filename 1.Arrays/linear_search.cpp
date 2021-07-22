#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,key;
	cin>>n;

	int a[1000];

	for( int i=0; i<n; i++){
		cin>> a[i];
	}

	cout<<"Enter the element that you wanna search :";
	cin>>key;
	int i;
	for ( i = 0; i <= n-1; i++)
	 {
	 	if (a[i] == key)
	 	{
	 		cout<<key<<" found at "<<i<<"th index.";
	 		break;
	 	}
	 } 
	 if(i == n){
	 	cout << key <<" is not present."<<endl;
	 }

}