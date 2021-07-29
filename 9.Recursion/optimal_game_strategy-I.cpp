#include <bits/stdc++.h>
using namespace std;

int F(int* arr, int i, int j) {
    //base code
    if (j == i+1) {
        return max(arr[i], arr[j]);
    }
    return max((arr[i] + min(F(arr, i+2, j), F(arr, i + 1, j - 1))),(arr[j]+ min(F(arr, i, j - 2), F(arr, i + 1, j - 1))));
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << F(arr, 0 , n - 1);

    return 0;
}
//https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/