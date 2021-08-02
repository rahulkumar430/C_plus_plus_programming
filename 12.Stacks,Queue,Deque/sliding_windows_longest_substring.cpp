//SPOJ sliding windows problem
//Length of the longest substring without repeating characters
//https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;

int main() {
	char a[] = "abbac";

	int n = strlen(a);
	int current_len = 1;
	int max_len = 1;

	int visited[256];

	for (int i = 0; i < 256; i++) {
		visited[i] = -1;
	}

	visited[a[0]] = 0;

	for (int i = 1; i < n; i++) {
		int last_occ = visited[a[i]];
		//cout << "last occ for " << i << "th index: " << last_occ << endl;
		//Expansion
		if (last_occ == -1 || i - current_len > last_occ) {
			current_len += 1;
			//cout << "updating curr length i IF to " << current_len << endl;
		}
		//Expansion + Contraction
		else {
			if (current_len > max_len) {
				max_len = current_len;
				//cout << "updating max length to " << max_len << endl;
			}
			current_len = i - last_occ;
			//cout << "updating curr length in ELSE to " << current_len << endl;
		}
		//cout << "visited[a[i]] = " << a[i] << " " << visited[a[i]] << endl;
		visited[a[i]] = i;
		//cout << "visited[a[i]] after changing= " << visited[a[i]] << endl;
	}

	if (current_len > max_len) {
		max_len = current_len;
		cout << "updating final max length to " << max_len << endl;
	}

	cout << max_len << endl;

	return 0;
}
