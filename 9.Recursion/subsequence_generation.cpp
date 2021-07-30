#include <bits/stdc++.h>
using namespace std;

static int cnt = 0;

void generate_subsequence(char *in, char *out, int i, int j, vector<string> &subsequence) {
	//base case
	if (in[i] == '\0') {
		out[j] = '\0';
		subsequence.push_back(out);
		cnt++;
		return;
	}
	//rec case
	//include the current char
	out[j] = in[i];
	generate_subsequence(in, out, i + 1, j + 1, subsequence);
	//exclude the current char
	generate_subsequence(in, out, i + 1, j, subsequence);
}

int main() {

	char input[10];
	cin >> input;
	char output[10];
	vector <string> subsequence;
	generate_subsequence(input, output, 0 , 0 , subsequence);
	reverse(subsequence.begin(), subsequence.end());
	for (int i = 0; i < subsequence.size(); i++)
	{
		cout << subsequence[i] << " ";
	}
	cout << endl;
	cout << cnt;
	return 0;
}