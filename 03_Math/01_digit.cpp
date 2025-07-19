#include <bits/stdc++.h>
using namespace std;

void extractDigits() {

    //* To get the digits
    //. T.C -> O(log10 (n))

    int n;
    cin >> n;

    while (n) {
        int lastDigit = n%10;

        cout << lastDigit << endl;

        n = n/10;
    }

    //* To count the digits

    //! Method-I
    // Follow the above method to count the digits


    //! Method-II
    int cnt = int (log10(n) + 1);

}