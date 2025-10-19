#include <bits/stdc++.h>
using namespace std;

// Problem 1: We have an array containing multiple elements with n/2 positive elements and n/2 negative elements. We need to rearrnage the elements such that positive and negative elements come alternatively. Also, the relative order of postive and negative elements with postives and negatives respectively must remain same. Note: In this variety there is an equal number of positives and negatives elements in the array

// Problem 2: See at the bottom

//* Method - I (Brute Force)

//. T.C -> O(n + n/2)
//. S.C -> O(n)
void bruteForce (int n, int arr[]) {
    vector<int>positives, negatives;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) positives.push_back(arr[i]);
        else negatives.push_back(arr[i]);
    }

    for (int i = 0; i < n/2; i++) {
       arr[2*i] = positives[i];
       arr[2*i + 1] = negatives[i];
    }

    // return arr

}

//* Method - II (Optimal Solution)

//. T.C -> O(n)
//. S.C -> O(n)
void optimalSolution(int n, int arr[]) {
    vector<int>ans(n);

    int pos = 0;
    int neg = 1;

    for (int i = 0; i < n; i++) {

        if (arr[i] >= 0) {

            ans[pos] = arr[i];
            pos += 2;

        }

        else {
            ans[neg] = arr[i];
            neg += 2;
        }

    }

    for (auto elem : ans) {
        cout << elem << " ";
    }

    cout << endl;
}

// Problem 2: Same as above problem, but we have unequal numbers of postives and negatives in the array. If after putting them alternatively, any of the postive or negatives are left, just add them as it is in the end.

//* Method - I (The brute force appraoch of the Problem 1 will be its final solution)

//. T.C -> O(n) + O(min(pos, neg)) + O(leftOvers) -> O(2*n) for the worst (when all have same sign)
//. S.C -> O(n)
void solutionPart2(int n, int arr[]) {

     vector<int>positives, negatives;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) positives.push_back(arr[i]);
        else negatives.push_back(arr[i]);
    }

   
    if (positives.size() >= negatives.size()) {

         // Put all the elements aleternatively till we run out of negatives

        for (int i = 0; i < negatives.size(); i++) {

            arr[2*i] = positives[i];
            arr[2*i + 1] = negatives[i];

        }

        // Fill in the remaining elements

        int index = negatives.size() * 2;
        for (int i = negatives.size(); i < positives.size(); i++) {

            arr[index] = positives[i];
            index++;

        }

    }

    else {
   for (int i = 0; i < positives.size(); i++) {

            arr[2*i] = positives[i];
            arr[2*i + 1] = negatives[i];

        }

        // Fill in the remaining elements

        int index = positives.size() * 2;
        for (int i = positives.size(); i < negatives.size(); i++) {

            arr[index] = negatives[i];
            index++;

        }

    }

    // return arr
}

