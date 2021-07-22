/* 
#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>&x, const pair<int, int>&y){
    return x.second < y.second;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		else {
			vector< pair <int, int> > vect;

			int arr[n] = {0};
			int arr1[n] = {0};
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i] >> arr1[i];
				// Entering values in vector of pairs
				vect.push_back( make_pair(arr[i], arr1[i]));
			}

			sort(vect.begin(), vect.end(),comp);

			int count = 1;

			for (int i = 1; i < n; i++)
			{
				if (vect[i - 1].second <= vect[i].first) {

					count++;

				}
			}
			cout << count << endl;
		}

	}

	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
     return a.second < b.second;
}

int main()
{
     int t;
     cin >> t;
     while (t--)
     {
          int n, a, b;
          cin >> n;
          pair<int, int> arr[n];
          for (int i = 0; i < n; i++)
          {
               cin >> a >> b;
               arr[i] = make_pair(a, b);
          }
          sort(arr, arr + n, cmp);
          int ans = 1, chosen = 0;
          for (int i = 1; i < n; i++)
          {
               if (arr[i].first >= arr[chosen].second)
               {
                    ans++;
                    chosen = i;
               }
          }
          cout << ans << endl;
     }
     return 0;
}