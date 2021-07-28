#include<bits/stdc++.h>
using namespace std;

int main () {
    unsigned long int primeNumber, testNumber = 1, testResult = 1;
    cin >> primeNumber;
    bool prime = false;
    while (!prime & (testNumber <= sqrt(primeNumber))) {
        testNumber++;
        testResult = primeNumber % testNumber;
        cout << testResult << endl;
        if (testResult == 0) {
            prime = true;
        }
    }
    if (prime) {
        cout << "first factor is : " << testNumber;
    }
    else {
        cout << "it's a prime number";
    }
    return 0;
}