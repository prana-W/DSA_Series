#include <bits/stdc++.h>
using namespace std;

// We want to get the maximum value and also carry less than or equal to the given capacity. Therefore, we find value per weight of all the items. We start taking items with the maximum value per weight, hence greddily making our costs go up and at last return the final answer

//. T.C -> O(n*log(n) + 2n)
//. S.C -> O(2n), due to storing the ratio and weight in the array
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        // TO store the ratio and weight of the item
        vector<pair<double, int>>perWt;
        
        for (int i = 0; i < wt.size(); i++) {

            double wtPerItem = ((double)(val[i]))/(double)(wt[i]);

            perWt.push_back({wtPerItem, wt[i]});

        }
        
        // Sorting and reversing to get the decreasing order
        sort(perWt.begin(), perWt.end());
        reverse(perWt.begin(), perWt.end());
        
        int req = capacity; // Maximum capcaity that we can hold
        
        double ans = 0;
        int i = 0;
        
        // Keep on iterating the perWt
        while (i < perWt.size() && req) {
            
            // Take either the total weight of the item or req, whichever is smaller
            int wt = min(perWt[i].second, req);
            
            // Add with the product of weigh tand ration, hence giving us the total value of the weigh taken
            ans += wt*perWt[i].first;
        
            req -= (wt);
            
            i++;
            
        }
        
        return ans;
        
        
    }