#include <bits/stdc++.h>
using namespace std;
//problem -> number to spellings
// 2048 ----> two zero four eight

char word[][10] = {"zero", "one", "two", "three", "four", "five", "six" , "seven" , "eight", "nine"};

void printSpellings(int n) {
	if (n == 0)
		return;

	printSpellings(n / 10);
	int digit = n % 10;
	cout << word[digit] << " ";
	return;
}

int main() {
	int n;
	cin >> n;

	printSpellings(n);
	return 0;
}