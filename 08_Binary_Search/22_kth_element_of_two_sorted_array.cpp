#include <bits/stdc++.h>
using namespace std;

// Problem: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// This is similar to the previous question. Instead of finding the middle element, we are finding the kth element. 

// Here, take k elements in the left side and rest in the right portion. Then the kth element (if the considered configuration is correct) is max(l1, l2)

//* Method - I and II (similar to the previous problem)

//* Method - III (Optimal Solution)
//. T.C -> O(log(min(n1, n2)))
//. S.C -> O(1)
int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();

        // Ensure a is smaller array for optimization
        if (n1 > n2) {
            // Swap a and b
            return kthElement(b, a, k); 
        }
        
        // Length of the left half
        int left = k; 

        // Apply binary search

        //! Observe, 'low' and 'high' is different from the previous question
        // We can't take 0 elements from first array, if k > n2. Similarly if we take all elements from the arr1 and k < n1, then it won't give correct answer, hence we change this only statement
        int low = max(0, k - n2), high = min(k, n1);

        while (low <= high) {

            int mid1 = (low + high)/2;
            int mid2 = left - mid1;

            // Initialize l1, l2, r1, r2
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

            // Check if we have found the answer
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            else if (l1 > r2) {
                // Eliminate the right half
                high = mid1 - 1;
            } 
            else {
                // Eliminate the left half
                low = mid1 + 1;
            }
        }
        
        return -1;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    //Print the answer
    cout << "The " << k << "-th element of two sorted arrays is: "
         << kthElement(a, b, k) << '\n';

    return 0;
}