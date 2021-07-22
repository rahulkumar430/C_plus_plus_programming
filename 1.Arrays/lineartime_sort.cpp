#include<bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void lineartime_sort(int a[], int n) {
/*	int i,j,k,l = 0;

	for(i = l;i<n;i++){
		if(a[i] == 0){
			swap(&a[i],&a[l]);
			l++;
		}
	}
    for(j = l;j<n;j++){
		if(a[j] == 1){
			swap(&a[j],&a[l]);
			l++;
		}
	}
	for(k = l;k<n;k++){
		if(a[k] == 2){
			swap(&a[k],&a[l]);
			l++;
		}
	}*/

	int low, mid, high;
	high = n-1;
	while(mid <= high){
		if(a[mid] == 0){
			swap(&a[low],&a[mid]);
			low++;
			mid++;
		}
		else if(a[mid] == 1){
			mid++;
		}
		else{
			swap(&a[mid],&a[high]);
			high--;
		}
	}
}

void printArray(int arr[], int n)  
{  
    int i;  
    for (i=0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}

int main() {
	int N;
	cin >> N;

	int a[N];

	for ( int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	lineartime_sort(a, N);
	printArray(a,N);

	return 0;
}