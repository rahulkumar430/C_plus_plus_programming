#include <bits/stdc++.h>
using namespace std;

bool isValidExp(char *stat){
	stack<char> s;
	for (int i = 0; stat[i] != '\0'; i++)
	{
		char ch = stat[i];
		if(ch == '(' or ch == '{' or ch == '[' ){
			s.push(ch);
		}
		else if(ch == ')'){
			if(s.empty() or s.top() != '(' ){
				return false;
			}
			s.pop();
		}
        else if( ch == '}'){
			if(s.empty() or s.top() != '{' ){
				return false;
			}
			s.pop();
		}
        else if(ch == ']' ){
			if(s.empty() or s.top() != '[' ){
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main(){
	char stat[100005];
	cin >> stat;
	if(isValidExp(stat)){
		cout << "Yes";
	}
	else{
		cout << "No";
	}

	return 0;
}