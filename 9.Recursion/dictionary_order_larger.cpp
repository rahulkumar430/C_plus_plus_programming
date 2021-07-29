/*
#include <bits/stdc++.h>
using namespace std;

void dictionary_larger(char *a, int j, int n) {
	if (n == 1)
		return;
	if (j == n - 1) {
		return dictionary_larger(a, 0, n - 1);
	}
	if (a[j] < a[j + 1]){
		swap(a[j], a[j + 1]);
		dictionary_larger(a, j + 1, n);
	}	
	return;
}

int main() {
	char str[10];
	cin >> str;
	int l = strlen(str);
	dictionary_larger(str, 0, l);
	cout << str;
	return 0;
}	*/

#include <bits/stdc++.h>
using namespace std;

string str;

void permute(string inp, string out)
{
    //Base case
    if (inp.size() == 0)
    {
        if (out > str)
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