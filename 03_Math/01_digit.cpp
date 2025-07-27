#include <bits/stdc++.h>
using namespace std;

// Problem: Find all the indivisual digits
void extractDigits() {

  //* To get the digits
  //. T.C -> O(log10 (n))

  int n;
  cin >> n;

  while (n) {
    int lastDigit = n % 10;

    cout << lastDigit << endl;

    n = n / 10;
  }
}

// Problem: Find the number of digits
void getDigits() {

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

// Problem: Reverse the number, if not possible, return 0

int reverseNumber(int x) {

  int reverseNum = 0;

  while (x) {
    int digit = x % 10;

    // this steps ensures, the number remains within the limit of int
    if (reverseNum > INT_MAX / 10 || reverseNum < INT_MIN / 10)
      return 0;
    reverseNum = reverseNum * 10 + digit;

    x /= 10;
  }
  return reverseNum;
}

bool armstrongNumber(int n) {

  int num = 0;
  int x = n;

  while (n) {
    int lastDigit = n % 10;

    num += pow(lastDigit, 3);

    n /= 10;
  }

  return num == x;
}