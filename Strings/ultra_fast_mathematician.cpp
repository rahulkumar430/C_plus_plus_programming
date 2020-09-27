#include <bits/stdc++.h>
using namespace std;

void answer(){
	string s1 = "";
	string s2= "";
	string ans;
	ans.clear();
	cin>>s1>>s2;

	for (int i = 0; i < s1.length(); i++)
	{
		if(s1[i] == s2[i]){
			ans.push_back('0');
		}
		else{
			ans.push_back('1');
		}
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		answer();
	}

	return 0;
}