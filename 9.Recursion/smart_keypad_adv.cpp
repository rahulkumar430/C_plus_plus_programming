#include <bits/stdc++.h>
using namespace std;

char keypad[][10] = { "", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
	"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
	"utkarsh", "divyam", "vidhi", "sparsh", "akku"
};

void generate_names(char *in, char *out, int i, int j, vector <string> &possible_result) {
	//base case
	if (in[i] == '\0') {
		out[j] == '\0';
		possible_result.push_back(out);
		return;
	}
	//rec case
	int digit = in[i] - '0';
	for (int k = 0; keypad[digit][k] != '\0'; k++) {
		out[j] = keypad[digit][k];
		//fill the remaining part
		generate_names(in, out, i + 1, j + 1, possible_result);
	}
	return;
}

void find_names(vector <string> &possible_result) {
	for (int i = 0; i < 11; i++)
	{
		string s2;
		s2.assign(possible_result[i]);

		for (int j = 0; j < possible_result.size(); j++)
		{
			string s1;
			s1.assign(searchIn[j]);
			if (s1.find(s2) != std::string::npos) {
				cout << s1 << '\n';
			}
		}
	}
}

int main() {
	char in[100];
	cin >> in;
	char out[100];
	vector <string> possible_result;
	generate_names(in, out, 0, 0, possible_result);
	find_names(possible_result);
	return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

vector<string> table = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> searchIn = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void phoneKeypad(string inp, string out)
{
    //Base case
    if (inp.size() == 0)
    {
        for (string ss : searchIn)
        {
            if (ss.find(out) != ss.npos)
            {
                cout << ss << endl;
            }
        }
        return;
    }

    //Rec case
    char ch = inp[0];
    string ros = inp.substr(1);
    string code = table[ch - '0'];

    for (int i = 0; i < code.length(); i++)
        phoneKeypad(ros, out + code[i]);
}

int main()
{
    string input;
    cin >> input;

    string output;
    phoneKeypad(input, output);
    return 0;
}


*/