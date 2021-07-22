/*According to the Problem the work is to find the Max CB numbers from the given number.

As to work on substrings of the given number, we will capture the element into the String instead of integer .
The number ‘n’ given is nothing to do with our approach(as we are working on String) but can be useful according to your approach.
Intuition to solve this problem:
Put loop on string that will give substring of every length.
create a function that will return true if the passed number is a CB number otherwise return false.
To put a check if the digit is already a part of the any other CB number, create an boolean array say,
valid which store which digits till now has been a part of any other CB number.
Take a counter and increment if a CB number is found.
At the end print the count.*/

#include <bits/stdc++.h>
using namespace std;

bool isCB(long long int n) {
	int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	if (n == 0 or n == 1) {
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (n == arr[i])
		{
			return true;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (n % arr[i] == 0)
		{
			return false;
		}
	}
	return true;
}

bool isValid(bool visited[17], string str,int start,int end)
{
    for(int i=start;i<end;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

int main() {
	int n,count=0;
	cin>>n;
	string str;
	cin>>str;

	bool visited[str.length()];// = {false};
	memset(visited,false,str.length());

    for(int len=1;len<=str.length();len++)
    {
        for(int start=0;start<=str.length()-len;start++)
        {            
            int end=start+len;

            string sub=str.substr(start,len);

            if(isCB(stoll(sub)) && isValid(visited,sub,start,end))
            {
            	count++;
                for(int i=start;i<end;i++)
                {
                    visited[i]=true;
                }
            }
        }
    }	
	cout<<count;

	return 0;
}