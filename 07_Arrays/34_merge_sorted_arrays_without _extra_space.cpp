#include <bits/stdc++.h>
using namespace std;

// Problem: Merge two sorted arrays without using extra space i.e. do it in-place

//* Method - hmmmm? (Naive Approach)
// Use the two-pointer appraoch as discussed in the 09_union of two sorted arrays lecture and then make the necessary changes in the input array, but there we were using some space. We want to solve the problem in-place, without using any extra space 
//. T.C -> O(2*(n+m))
//. S.C -> O(n+m)

//* Method - I (Optimal Approach I) 
// Keep a pointer to the extreme right of arr1 and another pointer in the start of arr2, if the elem1 > elem2, swap them, because, smaller element should occur in the first arr and then the second and keep on moving till there is no such element. At the last we have all the elements in its correct array. Now just sort both the arrays to arrange the elements in its correct position inside the arr

//. T.C -> O(min(n, m) + nlog(n) + mlog(m))
//. S.C -> O(1), as no extra space
void optimalSolution(vector<int>arr1, vector<int>arr2) {

    int n = arr1.size();
    int m = arr2.size();

    int left = n-1, right = 0;

    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {

            swap(arr1[left], arr2[right]);

            left--;
            right++;
        }
        else break;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

//* Method - I.V (Optimal Solution II)
//! Gap Method - Intuition comes from Shell Sort

void swapIfGreater(vector<int>arr1, vector<int>arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1],arr2[ind2]);
    }
} 

//. O(log(n+m) * O(n+m))
//. S.C -> O(1)
void optimalSecond(vector<int>arr1, vector<int>arr2) {

    int n = arr1.size();
    int m = arr2.size();

    int len = (n+m);
    
    int gap = (len / 2) + (len % 2); // or ceil(len*1.0/2.0)

    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {
            // arr1 and arr2
            if (left < n && right >= n) {

                swapIfGreater(arr1, arr2, left, right-n); // since right is greater than n, hterefore to get the index at arr2, subtract it from n

            }
            // arr2 and arr2
            else if (left >= n) {

                swapIfGreater(arr1, arr2, left-n, right-n);

            }
            // arr1 and arr1
            else {

                swapIfGreater(arr1, arr2, left, right);

            }

            left++;
            right++;
        }

        if (gap == 1) break;

        gap = (gap / 2) + (gap % 2); // or ceil(gap*1.0/2.0)
    }


}



