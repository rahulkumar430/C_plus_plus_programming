#include <bits/stdc++.h>
using namespace std;

/* Complete the extraLongFactorials function below.
#define MAX 500

int multiply(int x, int res[], int res_size);

void extraLongFactorials(int n) {
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    for (int i=res_size-1; i>=0; i--)
        cout << res[i];

}*/

/*int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod/10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
} */

// n = 5
// prod = [1]
// i = 2
// [2]
// i = 3
// [6]
// i = 4
// [4]
// carry = 2
// [4, 2]
// i = 5
// [0, 2, 1]
void multiply(vector<int> &prod, int i) {
    int carry = 0, curr_prod;

    for (int j = 0; j < prod.size(); j++) {
        curr_prod = (i * prod[j] + carry);

        // Extract the current digit and stored in the array
        prod[j] = curr_prod % 10;

        // Carry over the remaining
        carry = curr_prod / 10;
    }

    // Copy the remaining carry
    // 176 <-- carry
    // 176%10 = 6, 176/10 = 17
    // [4, 5, 9, 2, 1, 6]
    // 17 <-- carry
    // 17%10 = 7, 17/10 = 1
    // [4, 5, 9, 2, 1, 6, 7, 1]
    while (carry) {
        int curr_digit = carry % 10;
        prod.push_back(curr_digit);
        carry = carry / 10;
    }

}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector<int> prod;
    int i;

    // Initialize prod
    // prod = []
    // prod = [1]
    // prod = [1, 2]
    prod.push_back(1);

    for (i = 2; i <= n; i++)
        multiply(prod, i);

    // Print prod in reverse
    for (i = prod.size() - 1; i >= 0; i--)
        cout << prod[i];

    cout << endl;
}



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}