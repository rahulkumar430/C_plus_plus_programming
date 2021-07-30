#include <bits/stdc++.h>
using namespace std;

void x_to_theEnd(char *a, int i) {
	if (a[i] == '\0') {
		return;
	}
	else if (a[i] == 'x') {
		x_to_theEnd(a, i + 1);
	}
	else {
		cout << a[i];
		x_to_theEnd(a, i + 1);
	}
}

int main() {
	char a[1000];
	cin >> a;
	int cnt = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		if(a[i] == 'x'){
			cnt++;
		}
	}
	x_to_theEnd(a, 0);
	while(cnt--){
		cout << 'x';
	}
	return 0;
}

/*

// C++ implementation to Move all occurence of letter ‘x’
// from the string s to the end using Recursion
#include <bits/stdc++.h>
using namespace std;

// Function to move all 'x' in the end
void moveAtEnd(string s, int i, int l)
{
	if (i >= l)
		return;

	// Store current character
	char curr = s[i];

	// Check if current character is not 'x'
	if (curr != 'x')
		cout << curr;

	// recursive function call
	moveAtEnd(s, i + 1, l);

	// Check if current character is 'x'
	if (curr == 'x')
		cout << curr;

	return;
}

// Driver code
int main()
{
	string s = "geekxsforgexxeksxx";

	int l = s.length();

	moveAtEnd(s, 0, l);

	return 0;
}


*/


/*

// C++ program for above approach
#include<bits/stdc++.h>
using namespace std;

// Recursive program to bring 'x'
// to the end
void rec(char *a, int i)
{
	
	// When the string is completed
	// from reverse direction end of recursion
	if(i == 0)
	{
	cout << a << endl;
	return;
	}

	// If the character x is found
	if(a[i] == 'x')
	{
	
	// Transverse the whole string
	int j = i;
	while(a[j] != '\0' && a[j+1] != '\0')
	{
		
		// Swap the x so that
		// it moves to the last
		swap(a[j], a[j+1]);
		j++;
	}
	}

	// call to the smaller problem now
	rec(a, i - 1);
}

// Driver Code
int main()
{
	char a[] = {'g', 'e', 'e', 'k', 'x',
			's', 'x', 'x', 'k', 's', '\0'};
	
	// Size of a
	int n = 10;

	// Call to rec
	rec(a,n-1);
}
/* This code is contributed by Harsh kedia */


*/