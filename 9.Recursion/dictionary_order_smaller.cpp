#include <bits/stdc++.h>
using namespace std;

string str;

void permute(string inp, string out)
{
	//Base case
	if (inp.size() == 0)
	{
		if (out < str)
		{
			cout << out << endl;
		}
		return;
	}

	//Recursive case
	for (int i = 0; i < inp.size(); i++)
	{
		string ros = inp.substr(0, i) + inp.substr(i + 1);
		permute(ros, out + inp[i]);
	}
}
int main()
{
	cin >> str;

	string temp = str;

	sort(temp.begin(), temp.end());

	permute(temp, "");

	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

void swap(char& a, char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

bool lexicoCompare(vector <string> s1, vector <string> s2) {
	string key1, key2;
	key1 = s1[0];
	key2 = s2[0];

	return key1 < key2;
}

bool dictionary_smaller(string str, string curr) {
	if (str.compare(curr) <= 0) {
		return false;
	}
	else {
		return true;
	}
}

void permutation(string s, int i, int n, vector <string> &output)
{
	int j;
	if (i == n) {
		output.push_back(s);
	}
	else
	{
		for (j = i; j < s.length(); j++)
		{
			swap(s[i], s[j]);
			permutation(s, i + 1, n, output);
			swap(s[i], s[j]);
		}
	}
}

int main() {
	string str;
	cin >> str;
	int l = str.length();
	vector <string> output;
	permutation(str, 0, l - 1, output);
	int n = output.size();

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (output[i] > output[j]) {
				string temp = output[i];
				output[i] = output[j];
				output[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (dictionary_smaller(str, output[i])) {
			cout << output[i] << endl;
		}
	}
	return 0;
}
*/