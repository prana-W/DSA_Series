#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, My Approach)

// Note: Here candy <-> point

// Check the current index value with the neighbours and if conditions meet increase the point. Also the preivous scores depend on the current element's score, hence whenever we alter any value of pooints of any index, also go to the previous element for re-evaluation of that element

//. T.C -> O(n^2), due to going back to start in worst cases. 
//. S.C -> O(n)
int brute(vector<int>& arr) {

        int n = arr.size();

        // Give one candy to all
        vector<int>points(n, 1); 

        for (int i = 0; i < n; i++) {

            if (i+1 < n && arr[i] > arr[i+1] && points[i] <= points[i+1]) {
                points[i] = points[i+1] + 1;
                i = max(-1, i-2); // For re-evalutaion
            }

            if (i-1 >= 0 && arr[i] > arr[i-1] && points[i] <= points[i-1]) {
                points[i] = points[i-1] + 1;
                i = max(-1, i-2); // For re-evalutaion
            }

        }

        int ans = 0;

        for (auto elem : points) {
            ans += elem;
        }

        return ans;
        
}

//* Method - II (Better Approach)
// Compare current with left and make a single iteration and then compare current ith right and make another iteration in reverse

// Here points <-> candy

//. T.C -> O(3n)
//. S.C -> O(n)
int better(vector<int>& ratings) {

        int n = ratings.size();
        vector<int>points(n, 1);

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1] && points[i] <= points[i-1]) {
                points[i] = points[i-1] + 1;
            }
        }

        // Now right to left
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && points[i] <= points[i+1]) {
                points[i] = points[i+1] + 1;
            }
        }
        
        int ans = 0;

        for (auto elem : points) {
            ans += elem;
        }

        return ans;
}

//* Method - III (Optimal Approach)
//! Slope Concept

//? Page: 71. Watch lecture to better understand this method

//. T.C -> O(n)
//. S.C -> O(1)
int optimal(vector<int>& ratings) {

        int n = ratings.size();

        int sum = 1; // Include the first element
        int i = 1; // Start from second element

        while(i < n) {

            // If equal, then add 1 (we will give it one candy)
            if (ratings[i] == ratings[i-1]) {
                sum += 1;
                i++;
                continue;
            }

            // Consider peak

            int peak = 1;

            // Till peak
            while(i < n && ratings[i] > ratings[i-1]) {

                peak++;
                sum += peak;
                
                i++;
            }

            // Consider down
            int down = 1;

            // Till down
            while(i < n && ratings[i] < ratings[i-1]) {

                sum += down;
                down++;

                i++;

            }

            // Additional candies
            if (down > peak) sum += (down-peak);
        }
        
        return sum;
        
}