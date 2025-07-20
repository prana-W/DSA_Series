#include <bits/stdc++.h>
using namespace std;

//* HCF or GCD
// The highest/greatest commmon factor or divisor between two numbers

//. T.C -> O(min(n1, n2))
void gcdBruteForce(int n1, int n2) {
    int gcd = 1; // 1 is a common factor of all numbers

    // We loop till the min. number, since gcd can't be greater than the min. number
    for (int i = 1; i <= min(n1, n2); i++) {
        if (n1%i == 0 && n2%i == 0) gcd = i; // if the number is divides both n1 and n2, then it is a common factor
    }


    cout << gcd << endl;
}

//. T.C -> O(min(n1, n2))
// But, this is very much better solution than above. The worst case will be still min(n1, n2) though
void gcdAnotherApproach (int n1, int n2) {

    // We start the loop from the backwards, and the first common factor we encounter will be obviously be the greatest!
    for (int i = min(n1, n2); i >= 1; i--) {
        if (n1%i == 0 && n2%i == 0) { 
            cout << i << endl;
            break;
        }
    }
} 

//* Euclidean Algorithm *//
// It states that if you are given two numbers, n1 and n2, then the gcd(n1, n2) is equivalent to gcd(n1-n2, n2), where n1 > n2

// We keep on applying the above algorithm on the two numbers, till one of the number becomes zero. In such a case, the other non-zero number would be the GCD off the two numbers.
// But if the n1 is greater, we might end up doing repitative subtraction of second number from the first, till the first becomes smaller and then so on. So isn't it better to just get the reminder, rather than doing repitative subtraction?

//* gcd(n1, n2) == gcd(n1%n2, n2), where n1 > n2 
// Apply the above till one number becomes zero, then the other numebr is the gcd of the two numbers initially.

// GCD of a and b
//. T.C (O(log base phi (min(a, b))))
// log appeared, since division is happening again and again
// phi is a variable depending on a and b
void euclideanAlgorithm (int a, int b) {

    if (a == b) cout << a << endl; // When both the numbers are equal

    while (a > 0 && b > 0) {

        if (a > b) a = a % b;
        else b = b % a;

    }

    if (a == 0) cout << b << endl;
    else cout << a << endl;

}