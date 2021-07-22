// A C++ Program to find the longest common prefix 

#include <bits/stdc++.h>
using namespace std;

// A Utility Function to find the common prefix between 
// strings- str1 and str2 
string commonPrefixUtil(string str1, string str2) 
{ 
	string result; 
	int n1 = str1.length(), n2 = str2.length(); 

	// Compare str1 and str2 
	for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
	{ 
		if (str1[i] != str2[j]) 
			break; 
		result.push_back(str1[i]); 
	} 

	return (result); 
} 

// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix (string arr[], int n) 
{ 
	string prefix = arr[0]; 

	for (int i=1; i<=n-1; i++) 
		prefix = commonPrefixUtil(prefix, arr[i]); 

	return (prefix); 
} 

// Driver program to test above function 
int main() 
{ 
	string arr[] = {"geeksforgeeks", "geeks", 
					"geek", "geezer"}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	string ans = commonPrefix(arr, n); 

	if (ans.length()) 
		printf ("The longest common prefix is - %s", 
				ans.c_str()); 
	else
		printf("There is no common prefix"); 

	return (0); 
} 


/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
             return "";
        int i,j;
        string lcp = "";
        char curr_char;
        for(i = 0; i < strs[0].size(); i++){
            //checking characters of words in strs at position
            curr_char = strs[0][i];
            for(j = 0;j < strs.size();j++){
                if(strs[j][i] != curr_char)
                    break;
            }
            //all the characters were equal 
            if(j == strs.size())
                lcp += curr_char;
            else
                break;
        }
        return lcp;
    }
};
*/