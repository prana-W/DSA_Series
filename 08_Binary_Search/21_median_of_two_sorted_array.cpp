#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Merge (by one pointer in each array and putting the value whichever is smaller into another joint array) and find the middle element or the mean of the two middle elements
//. T.C -> O(n1 + n2)
//. S.C -> O(n1 + n2)

//* Method - II (Better Solution)
// Find the middle index before hand and stop when we encounter that element, this optimises the space complexity

//. T.C -> O(n+m)
//. S.C -> O(1)

void betterSolution(vector<int>arr1, vector<int>arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    int n = (n1+n2); // total number of elements

    //! These are the indices of the required element in the hypothetical sorted and joint array
    //! If n -> odd, just find the element at ind1 else if n -> even, find both element at ind1 and ind2 and return there mean
    int ind1 = n/2 - 1;
    int ind2 = ind1 + 1;

    int i = 0, j = 0; // Pointer to move in both arrays respectively

    int elemAtInd1 = INT_MIN, elemAtInd2 = INT_MIN;

    int index = 0; // this is tracking the index of the hhypothetical joint array
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {

            if (index = ind1) elemAtInd1 = arr1[i];
            if (index = ind2) elemAtInd2 = arr1[i];

            i++;
            index++;
        }
        else {

            if (index = ind1) elemAtInd1 = arr2[i];
            if (index = ind2) elemAtInd2 = arr2[i];

            j++;
            index++;
        }
    }

    while (i < n1) {

        if (index = ind1) elemAtInd1 = arr1[i];
        if (index = ind2) elemAtInd2 = arr1[i];

        i++;
        index++;
    }

    while(j < n2) {

        if (index = ind1) elemAtInd1 = arr2[i];
        if (index = ind2) elemAtInd2 = arr2[i];

        j++;
        index++;
    }

    double ans = -1;

    // If n is odd, then just find the elemAtInd1
    if (n%2 != 0) ans = elemAtInd1;
    else ans = double(elemAtInd1 + elemAtInd2)*1.0/2;

    cout << ans << endl;

}

//* Method - III (Optimal Solution)

//. T.C -> O(log(min(n, m)))
//. S.C -> O(1)
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // Ensure a is the smaller array to minimize binary search scope
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);

        int n1 = a.size(), n2 = b.size();
        int low = 0, high = n1;

        // Binary search on the smaller array
        while (low <= high) {
            // Calculate the cut positions for both arrays
            int mid1 = (low + high) / 2; 
            int mid2 = (n1 + n2 + 1) / 2 - mid1;

            // Handle boundary elements using INT_MIN and INT_MAX
            int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

            // If correct partition is found
            if (l1 <= r2 && l2 <= r1) {
                // Total even => average of max left and min right
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    // Total odd => max of left half
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                // Shift left in a
                high = mid1 - 1;
            }
            else {
                // Shift right in a
                low = mid1 + 1;
            }
        }

        return 0.0;
}


int main() {
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << "Median is: " << findMedianSortedArrays(a, b) << endl;
    return 0;
}
