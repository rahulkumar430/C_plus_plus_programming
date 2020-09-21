#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m;
	int a1[1001] = {0};
	string s1="";
	for (int i = 0; i < m; i++)
	{
		cin >> a1[i];
		s1+=(to_string(a1[i]));
	}
	int n1 = stoi(s1);

	cin >> n;
	int a2[1001] = {0};
	string s2;
	for (int i = 0; i < n; i++)
	{
		cin >> a2[i];
		s2.append(to_string(a2[i]));
	}
	int n2 = stoi(s2);

	int sum = n1+n2;

	string s="";
	s = to_string(sum);

	for(int i=0;i<s.length();i++){
		cout<<s[i]<<", ";
	}
	
	cout << "END" << endl;
	return 0;
}