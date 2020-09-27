#include <bits/stdc++.h>
using namespace std;

int main() {
	string S = "";
	getline(cin, S);

	string temp = "";
	int count = 0;

	temp[0] = S[0];

	for (int i = 0; i <= S.length(); i++) {
		if(temp[0] == S[i]){
			count++;
		}
		else{
			cout<<temp[0]<<count;
			temp.clear();
			temp[0] = S[i];
			count = 1;
		}
	}
	return 0;
}