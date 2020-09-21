#include <bits/stdc++.h>
using namespace std;

int actualSize(int num[], int n){
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if(num[i+1] > num[i])
			count++;
	}
	return count;
}

void printElement(string S,int m, int n){
	for(int i=m; i<n;i++){
		cout<<S[i];
	}
		cout<<endl;	
}

int main() {
	string S = "";
	getline(cin, S);

	int num[S.length()] = {0};
	int j=0;
	for (int i = 0; i < S.length(); i++)
	{
		if(isupper(S[i])){
			num[j] = i;
			j++;
		}
	}

	int l = actualSize(num,S.length());
	
	int arr[l+1] = {0};

	for (int i = 0; i < l; i++)
	{
		arr[i] = num[i];
	}
	arr[l] = S.length();
	
	for (int i = 0; i < l; i++)
	{
		printElement(S, arr[i], arr[i+1]);
	}

	return 0;
}
