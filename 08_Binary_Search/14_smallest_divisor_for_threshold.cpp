#include <bits/stdc++.h>
using namespace std;


pair<int, int> sumAndMaxElement(vector<int>arr) {

        long long sum = 0;
        int maxi = INT_MIN;

        for (auto elem : arr) {
            maxi = max(maxi, elem);
            sum += elem;
        }

        if (sum > INT_MAX) sum = INT_MAX;

        return {maxi, sum};

}

// Find the total sum for a given input
int findSumAfterDivision(vector<int>arr, int mid) {
        
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += ceil(arr[i]*1.0/mid);

        }

        return sum;
}
    
//* Method - I (Brute Force)
//. T.C -> O(n*M), M: Maximum Element

//* Method - II (Optimal Solution)
//. T.C -> O(n*log(M))

//! As we are asked minimum (or maximum if it had been), we can think of binary search on answer

int smallestDivisor(vector<int>& nums, int threshold) {

        pair<int, int>result = sumAndMaxElement(nums);
        int totalSum = result.second;
        int maxElem = result.first;

        // If we take divisor as equal to maximum element or even INFNITY, our total sum would be equal to nums.size(), hence smaller value than that is not possible
        if (threshold < nums.size()) return -1;

        int low = 1, high = maxElem;

        while(low <= high) {
            int mid = low + (high - low)/2;
            int sum = findSumAfterDivision(nums, mid);

            if (sum <= threshold) high = mid - 1; // if sum is less than threshold, try decreasing divisor, as that will increase the sum. If sum is equal to threshold, we still try a smaller divisor, as we are asked smallest divisor
            else low = mid + 1;
        }

        return low;

}