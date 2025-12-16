#include <bits/stdc++.h>
using namespace std;

// Problem: Find floor of square root of a number


//* My code
int sqrtRoot(int n) {

    int low = 1;
    int high = n;

    int ans = -1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (mid*mid == n) {

            ans = mid;
            break;

        }

        else if (mid*mid < n) {
            ans = mid;
            low = mid + 1; // store ans and move to the right
        }

        else high = mid-1;
    }

    return ans;
}

//* Sir code

int anotherCode(int n) {

    int low = 1, high = n;


    while (low <= high) {
        int mid = (low+high)/2;
        int val = mid*mid;

        if (val <= n) low = mid+1; // go to the right side, if exceeds our ans, then high in later step will go back to previous value and it will break, as high would have crossed low
        else high = mid-1;

    }

    return high;

}