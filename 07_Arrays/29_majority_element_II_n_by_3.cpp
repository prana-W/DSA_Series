#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array containing integers. Return all the elements that appear more than floor(n/3) times

//* Method - I (Brute Force)
// Iterate the array twice and count the frequency of each element and check if it is > Floor(n/3). For every answer store it an answer array and before iterating for anny given element, check if it already is an answer. 
//! Also, note there could only be two answers at max!!! Only two elements with freuqncy greater than Floor(n/3) could occur in an array of sie n

//. T.C -> O(n^2)
//. S.C -> O(1)

//* Method - II (Better Solution)
//! Hashing/Hash Map
// Iterate thorugh the array once and store the frequncy in the map (could be unordered) and then iterate thorugh the map and return all the elements that match the condition

//. T.C -> O(n*log(n)) for ordered map
//. S.C -> O(n)

//* Method - III (Optimised Solution)

//. T.C -> O(n)
//. S.C -> O(1)
vector<int> optimalSolution(vector<int>arr) {

    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int elem1 = INT_MIN, elem2 = INT_MIN;

    //! Step 1: Applying Moore's Voting Algorithm for n/3

    for (int i = 0; i < n; i++) {

        // Only track this into elem1, if not already tracked by elem2
        if (cnt1 == 0 && elem2 != arr[i]) {
            cnt1++;
            elem1 = arr[i];
        }
        // Only track this into elem2, if not already tracked by elem1
        else if (cnt2 == 0 && elem1 != arr[i]) {
            cnt2++;
            elem2 = arr[i];
        }
        else if (arr[i] == elem1) cnt1++;
        else if (arr[i] == elem2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    //! Step 2: Manually checking if our answer is correct. Necessary for Moore's voting algorithm

    vector<int>ans;
    cnt1 = 0, cnt2 =0;

    for (int i = 0; i < n; i++) {
        if (elem1 == arr[i]) cnt1++;
        if (elem2 == arr[i]) cnt2++;
    }

    int required = n/3;

    if (cnt1 > required) ans.push_back(elem1);
    if (cnt2 > required && elem2 != elem1) ans.push_back(elem2);

    sort(ans.begin(), ans.end());

    return ans;
}