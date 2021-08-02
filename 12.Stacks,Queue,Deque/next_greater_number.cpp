#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!s.empty() && nums[s.top()] <= nums[i % n])
        {
            s.pop();
        }

        res[i % n] = (s.empty() ? -1 : nums[s.top()]);
        s.push(i % n);
    }

    return res;
}

void printNGE(vector<int> nums, int n)
{
    int k;
    for (int i = 0; i < n; i++) {
        //cout << "i value: " << i << endl;
        // Initialise k as -1 which is printed when no NGE found
        k = -1;
        for (int j = i + 1; j < n + i; j++) {
            //cout << "j value: " << j << endl;
            if (nums[i] < nums[j % n]) {
                cout << nums[j % n] << " ";
                k = 1;
                break;
            }
        }
        if (k == -1) // Gets executed when no NGE found
            cout << "-1 ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = nextGreaterElements(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    printNGE(v, n);

    return 0;
}