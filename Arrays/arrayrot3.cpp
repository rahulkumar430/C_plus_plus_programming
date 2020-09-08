#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";	
	} 
}

int main(){
	int n,l,d;
	int * arr;

	cin>>n;

	cout<<"enter array elements"<<endl;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<"howmany left rotation: "<<endl;
	cin>>l;
	if(l<n){
		d=l;
	}
	else{
		d=l%n;
	}
	//pointer and array are a bit different and don't ever start a array witout assigning anything cause i missed ={0};
	int temp[d]={0};
//store first d elements in temp array
	for(int i=0;i<d;i++){
		temp[i]=arr[i];
	}
//shift d towwards left
	for(int i=0;i<n-d;i++){
		arr[i]= arr[i+d];
	}
//restore the elements to main array
	for(int i=0;i<d;i++){
		arr[n-d+i] = temp[i];
	}

	printArray(arr,n);
	return 0;
}
