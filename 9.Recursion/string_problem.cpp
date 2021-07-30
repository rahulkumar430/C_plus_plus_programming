#include<bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key) {
	//strtok
	char *s = strtok((char *)str.c_str(), " ");	//typecasting c_str = c style string basically ending with null

	/*The basic_string::c_str() is a builtin function in C++ which returns a pointer to an array that contains
	a null-terminated sequence of characters representing the current value of the basic_string object.*/

	//char* is a pointer to the first char in the return "string" (char array)
	while (key > 1) {
		s = strtok(NULL, " ");
		key--;
	}
	return (string)s;
}

/*int convertToInt(string s) {
	int ans = 0;
	int p = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += ((s[i] - '0') * p);
		p = p * 10;
	}
	return ans;
}*/

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	//return convertToInt(key1) < convertToInt(key2);
	return stoi(key1) < stoi(key2);  //instead of using a string into int converter on our own we can use a pre built function of it.

}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return key1 < key2;
}

int main() {

	int n;
	cin >> n;
	cin.get();

	string a[100];
	for (int i = 0; i < n; i++)
	{
		getline(cin, a[i]);
	}

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	pair<string, string> strPair[100]; 
	//To know more about pairing --->>> https://www.geeksforgeeks.org/pair-in-cpp-stl/#:~:text=The%20pair%20container%20is%20a,may%20be%20different%20in%20type.

	for (int i = 0; i < n; i++)
	{
		strPair[i].first = a[i];
		strPair[i].second = extractStringAtKey(a[i], key);
	}

	//sorting
	if (ordering == "numeric") {
		sort(strPair, strPair + n, numericCompare);
	}
	else {
		sort(strPair, strPair + n, lexicoCompare);

	}

	if (reversal == "True") {
		for (int i = 0; i < n / 2; i++) {
			swap(strPair[i], strPair[n - i - 1]);
		}
	}

//print the output
	for (int i = 0; i < n; i++)
	{
		cout << strPair[i].first << " " << endl;
	}

	return 0;
}