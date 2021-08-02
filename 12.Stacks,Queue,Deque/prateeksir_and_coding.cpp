#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q, i;
	cin >> q;
	stack<int> s;
	for (i = 0; i < q; i++)
	{
		int a, b;
		cin >> a;
		if (a == 1)
		{
			if (s.empty())
				cout << "No Code" << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else
		{
			cin >> b;
			s.push(b);
		}
	}

	return 0;
}