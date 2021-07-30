#include <bits/stdc++.h>
using namespace std;

void displaySubset(int subSet[], int size) {
   for (int i = 0; i < size; i++) {
      cout << subSet[i] << "  ";
   }
   cout << endl;
}

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount , int sum) {
   if ( total == sum) {
      displaySubset(subSet, subSize);     //print the subset
      subsetSum(set, subSet, n, subSize - 1, total - set[nodeCount], nodeCount + 1, sum); //for other subsets
      return;
   } else {
      for ( int i = nodeCount; i < n; i++ ) {    //find node along breadth
         subSet[subSize] = set[i];
         subsetSum(set, subSet, n, subSize + 1, total + set[i], i + 1, sum); //do for next node in depth
      }
   }
}

void findSubset(int set[], int size, int sum) {
   int *subSet = new int[size];     //create subset array to pass parameter of subsetSum
   subsetSum(set, subSet, size, 0, 0, 0, sum);
   delete[] subSet;
}


int main() {
   int weights[] = {10, 1, 2, 7, 6, 1, 5};
   int size = 7;
   findSubset(weights, size, 8);
}

/*
#include<bits/stdc++.h>
#define ll long long
using namespace std ;

set<vector> mp;
void sum_it_up(vector out, vector&a, ll i, ll t, ll n)
{
//base case
   if (t == 0)
   {
      if (mp.find(out) == mp.end())mp.insert(out);
      return;
   }
   if (i >= n)return;

//recurrsive case

   if (a[i] <= t)
   {
      out.push_back(a[i]);
      sum_it_up(out, a, i + 1, t - a[i], n);
      out.pop_back();
   }

   sum_it_up(out, a, i + 1, t, n);
}
int main() {
   ll int n, t;
   cin >> n;
   vectorout; vectorv;
   for (int i = 0; i < n; i++)
   {
      ll int x;
      cin >> x;
      v.push_back(x);
   }
   cin >> t;
   sort(v.begin(), v.end());
//for(auto a:v)cout<<a<<" “;
   sum_it_up(out, v, 0, t, n);
   for (auto a : mp)
   {
      for (auto it = a.begin(); it != a.end(); it++)cout << *it << " ";
      cout << endl;
   }
   return 0;
}
*/