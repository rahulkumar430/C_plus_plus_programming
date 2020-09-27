#include <bits/stdc++.h>
using namespace std;

int sankatandstrings(int num, string S) {
	int l = S.length();
	int count_a = 0;
	int count_b = 0;

	for (int i = 0; i < l; i++)
	{
		if (S[i] == 'a') {
			count_a++;
		}
		else{
			count_b++;
		}
	}

	if (min(count_a,count_b) >= num){
		return (max(count_a,count_b)+num);
	}
	else{
		return (count_a+count_b);
	}

}

int main() {

	int num;
	cin >> num;

	string S = "";
	cin >> S;

	cout << sankatandstrings(num, S) << endl;

	return 0;
}