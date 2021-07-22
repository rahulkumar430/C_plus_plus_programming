#include<bits/stdc++.h>
using namespace std;

void printelement(int temp[],int n){
	    for (int i = 0; i < n; i++) 
        cout << temp[i] << " ";
}


int main(){
int n,d;
int * arr;

cin>>n;

cout<<"enter array elements"<<endl;

for(int i=0;i<n;i++){
	cin>>arr[i];
	}

cout<<"howmany left rotation: "<<endl;
cin>>d;
int * temp;

for(int i=0;i<n-1;i++){
	temp[i]= arr[i+2];
}
for(int i=0;i<d;i++){
	temp[n-1+i]=arr[i];
}
printelement(temp,n);
		return 0;
}