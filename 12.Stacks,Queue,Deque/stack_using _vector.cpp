#include <bits/stdc++.h>
using namespace std;

template<typename T>
//for muiltiple data types -> template<typename T, typename U>

class Stack{
private:
	vector<int> v;
public:
	void push(T data){
		v.push_back(data);
	}
	bool empty(){
		return v.size()== 0;
	}
	void pop(){
		if(!empty()){
			v.pop_back();
		}
	}
	T top(){
		return v[v.size()-1];
	}
};

int main(){
	/*Stack <int> s;

	for (int i = 1; i <= 5; i++)
	{
		s.push(i*i);
	}*/

	Stack <char> s;

	for (int i = 65; i <= 70; i++)
	{
		s.push(i);
	}


	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	
	return 0;
}