#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
	/*if(a.length() == b.length()){
		return a<b;
	}
	return a.length() > b.length();*/
	//if (a.find(b) != std::string::npos) {
	if (a.find(b)==0 || b.find(a)==0) {
		return a > b;;
	}
	return a < b;
}

int main() {
	int n;
	cin >> n;
	cin.get();
	string s[100];	//vector

	for (int i = 0; i < n; i++)
	{
		getline(cin, s[i]);
	}
	sort(s, s + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << s[i] << endl;
	}

	return 0;
}