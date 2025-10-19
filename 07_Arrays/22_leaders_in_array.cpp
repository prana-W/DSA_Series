#include <bits/stdc++.h>
using namespace std;

// Problem: An element in the array is the leader, if everything in its right is smaller than that element. So return the array of all the leaders

//* Method - I (Brute Force)

// Iterate through each element and iterate to its right and check if all are smaller than the element, and store it in leaders array.

//. T.C -> O(n^2), nearly
//. S.C -> O(1), since no extra space, or consider O(n) if considering space for storing the space in the worst case
void brute(int n, int arr[]) {

    vector<int>leaderArr;

    for (int i = 0; i < n; i++) {

        bool isLeader = true;

        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }

        if (isLeader) leaderArr.push_back(arr[i]);
    }

    for (auto elem : leaderArr) {
        cout << elem << " ";
    }
    cout << endl;
}

//* Method - II (Optimal Solution)

// If any element is the greatest than all the elements in its right, then store that element

//. T.C -> O(n + x), x is depending on how we are returning the answer, if sorted x would be nlog(n) and so on...
//. S.C -> O(n) for storing, but no for extra that is O(1)
void optimalSolution (int n, int arr[]) {

    int maxi = INT_MIN;

    vector<int>leaderArr;

    for (int i = n-1; i >= 0; i--) {

        if (arr[i] > maxi) {
            leaderArr.push_back(arr[i]);
        }

        maxi = max(maxi, arr[i]);

    }

    reverse(leaderArr.begin(), leaderArr.end()); // since we want to conserver the relative order of the leader elements (if asked to sort, we can sort it)

    for (auto elem : leaderArr) {
        cout << elem << " ";
    }
    cout << endl;

}