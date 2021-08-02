#include <bits/stdc++.h>
using namespace std;

bool isValidExp(char *stat){
	stack<char> s;
	for (int i = 0; stat[i] != '\0'; i++)
	{
		char ch = stat[i];
		if(ch == '('){
			s.push(ch);
		}
		else if(ch == ')'){
			if(s.empty() or s.top() != '('){
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main(){
	char stat[100] = "((a+b)+(c-d+f)";
	if(isValidExp(stat)){
		cout << "Valid Expression";
	}
	else{
		cout << "Not a valid Expression";
	}

	return 0;
}