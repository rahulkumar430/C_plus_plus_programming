#include <bits/stdc++.h>
using namespace std;

int main(){
	list<int> l;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		l.push_back(data);
	}
	int temp = n/2;
	while(temp--){
		if(l.front() == l.back()){
			l.pop_front();
			l.pop_back();
		}
		else{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}