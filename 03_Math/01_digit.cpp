#include <bits/stdc++.h>
using namespace std;

void extractDigits()
{

    //* To get the digits
    //. T.C -> O(log10 (n))

    int n;
    cin >> n;

    while (n)
    {
        int lastDigit = n % 10;

        cout << lastDigit << endl;

        n = n / 10;
    }
}

void getDigits()
{

    int n;
    cin >> n;

    //* To count the digits

    //! Method-I
    //. T.C -> O (log10 (n))

    // Follow the method of extractDigits() to count the digits

    //! Method-II
    //. T.C -> O(1)

    int cnt = int(log10(n) + 1);
}

// Reverse the number
// If not possible, return 0

// https://leetcode.com/problems/reverse-integer
int reverseNumber(int x)
{

    int reverseNum = 0;

    while (x)
    {
        int digit = x % 10;

        // this steps ensures, the number remains within the limit of int
        if (reverseNum > INT_MAX / 10 || reverseNum < INT_MIN / 10)
            return 0;
        reverseNum = reverseNum * 10 + digit;

        x /= 10;
    }
    return reverseNum;
}

bool armstrongNumber(int n)
{

    int num = 0;
    int x = n;

    while (n)
    {
        int lastDigit = n % 10;

        num += pow(lastDigit, 3);

        n /= 10;
    }

    return num == x;
}

void allDivisors(int n)
{
    //* Method-I (Brute-force)
    //. T.C -> O(n)

    /*
      for (int i = 1; i <= n; i++) {
          if (n%i == 0) cout << i << " ";
      }

      */

      //* Method-II (Optimised Way)
      // See obsidian notes

      // Use vector to store the data and then sort!
      
      vector<int>arr;

      int squareRoot = sqrt(n); // storing the result in a varible, so that the function sqrt(n) is not called again and again in the loop, thus optimising the code a little bit

      // T.C for the loop -> O(sqrt(n))
      for (int i = 1; i <= squareRoot; i++) {
          if (n%i == 0) {
            arr.push_back(i);
            if (n/i != i) arr.push_back(n/i);
          }
      }

      // T.C for sort: O(nf*log(nf))
      sort(arr.begin(), arr.end());

      // T.C for this loop: O(nf), where nf is the number of factors
      for (auto element: arr) {
        cout << element << " ";
      }

      //. T.C for the entire function: O(sqrt(n)) + O(nf*log(nf)) + O(nf)

}