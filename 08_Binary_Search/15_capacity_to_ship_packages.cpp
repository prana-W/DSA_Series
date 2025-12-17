#include <bits/stdc++.h>
using namespace std;

// Returns the total number of days required to ship packages with a total weight equal to weight in a day
int checkFn(vector<int>arr, int weight) {
        int totalDays = 0;

        int w = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (w <= weight) w += arr[i];

            if (w > weight) {
                totalDays++;
                w = arr[i];
            }


        }

        if (w > 0) totalDays++;

        return totalDays;
}

//* Method - I (Brute Force)

// Iterate a loop from a minimum possible answer to maximum possible answer and for each iteration also check if the totalDays that we are getting is <= requied, else break and report the answer

int bruteForce(vector<int>weights, int days) {

    int sum = 0;
    int maxi = INT_MIN;

    for (auto elem : weights) {
            sum += elem;
            maxi = max(maxi, elem);
    }


    int minimumCapacity = maxi;
    int maximumCapacity = sum;

    for (int i = minimumCapacity; i <= maximumCapacity; i++) {
        if (checkFn(weights, i) <= days) return i;
    }
}


int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;
        int maxi = INT_MIN;

        for (auto elem : weights) {
            sum += elem;
            maxi = max(maxi, elem);
        }

        // Here low and high is for capacity

        // we can't ship all the pacakges, if minimum weight of a package is less than the maxium weight (as the least package would not be able to shipped)
        int low = maxi, high = sum;
        // If we have high as sum, we can deleiver all the pacakges in a day

        while (low <= high) {
            int mid = (low + high)/2;

            int totalDays = checkFn(weights, mid);

            if (totalDays <= days) high = mid - 1; // if we can ship packages in less than required days, we can probably use less package weight a day and maybe still be under days, hence we move left
            else low = mid + 1; // if we are taking more time to deliver packages, we have to increase the capacity of our ship
        }

        return low;

}
