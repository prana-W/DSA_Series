#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//* Method - I (Brute Force)
// Use any sorting algorithm
//. T.C -> O(n*log(n)) 
//. S.C -> O(n) for merge sort

//* Method - II (Better Solution)
// Make a freq array and get the freq of 0, 1 and 2
// Then run the loop and place all the elements by overwriting for 0, then 1 and then 2
//. T.C -> O(2*n)
//. S.C -> O(1) for extra space

//* Method - III (Optimal Solution)
//! Dutch National Flag Algorithm

// arr[mid] == 0, swap with arr[low] and move low and mid
// arr[mid] == 1, move move mid
// arr[mid] == 2, swap with arr[high] and lower high

//. T.C -> O(n)
//. S.C -> O(1)
void optimalDutchNationalFlag(int n, int arr[]) {
    int low = 0, mid = 0, high = n-1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) mid++;

        else {
            swap(arr[mid], arr[high]);
            high--;
        }

    }
} 