#include<bits/stdc++.h>
using namespace std;

//char strtok(char *s,char *delimiters)
//returns a token after every subsequent cell
//on the first call function should be passed with string arguement for 's'
//on sebsequent cells we have the pass the string arguement as NULL


int main() {

	char s[100] = "Today is a rainy day.";
	/*	for (int i = 0; i < n; i++)
		{
			getline(cin, s[i]);
		} */

	char *ptr = strtok(s, " ");
	cout << ptr << endl;

	while(ptr != NULL){
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}

	return 0;
}