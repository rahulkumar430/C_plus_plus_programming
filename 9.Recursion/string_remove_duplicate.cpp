#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s)
{
	if (s.size() <= 1)
	{
		return s;
	}

	string ros = removeDuplicate(s.substr(1));	//substr(i) == i th position to last position
	//cout <<"ros[0]: "<<ros[0] << endl;
	//cout <<"s[0]: "<<s[0] << endl;

	if (s[0] == ros[0])
	{
		return ros;
	}

	return s[0] + ros;
}

int main()
{
	string s;
	cin >> s;

	cout << removeDuplicate(s) << endl;

	return 0;
}