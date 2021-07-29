#include <bits/stdc++.h>
using namespace std;

//How do you make a C++ program that will display all possible 10 letter combinations if you input English Alphabet (26 letters)?

static void permute(const std::string &base, int count)
{
	if (!count) {
		cout << base << '\n';
	} else {
		for (char l = 'a'; l <= 'z'; ++l) {
			permute(base + l, count - 1);
		}
	}
}

int
main()
{
	permute("", 2);
	return 0;
}