#include <bits/stdc++.h>
using namespace std;

int ascii(char c){
	int i= c;
	return i;
}

int main() {
	string S = "";
	getline(cin,S);

	int l = S.length();

	int num[l] = {0} ;

	for (int i = 0; i < l - 1; i++)
	{
		num[i] = (ascii(S[i+1]) - ascii(S[i]));
	}

	for (int i = 0; i < l - 1; i++)
	{
		cout<<S[i]<<num[i];
	}
	cout<<S[l-1]<<endl;
	return 0;
}