#include<bits/stdc++.h>
using namespace std;

int main() {
	string S = "";
	getline(cin, S);

	string temp = "";
	int count = 0;
	int max = INT_MIN;

	string freq = "";
	int cmp = 0;

	for (int i = 0; i < S.length(); i++) {
		//int cmp = strcmp(S[i],temp[i]);
		if (S[i] == temp[0]) {
			cmp = 1;
		}
		else {
			cmp = 0;
		}
		temp.clear();
		if (cmp == 0) {
			temp[0] = S[i];
			for (int j = 0; j < S.length(); j++)
			{
				if (temp[0] == S[j])
				{
					count++;
				}
			}
			if (max < count) {
				max = count;
				freq[0] = temp[0];
			}
			count = 0;
		}
	}
	cout << freq[0] << endl;
	return 0;
}