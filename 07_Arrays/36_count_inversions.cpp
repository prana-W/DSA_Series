#include <bits/stdc++.h>
using namespace std;

//! Note: Kindly revisit Merge Sort before revising this problem

// Problem: Given an array of integers, find out number of pairs ordered in such a way such that left element should be greater than the right element
// Example: [5 3 2 4 1]
// Output: [5 3], [5 2], [5 4], [5 1], [3 2], [3 1], [2 1], [4 1] -> Return 8 (number of pairs)

//* Method - I (Brute Force)
// Generate all the possible pairs and check if condition valid

//. T.C -> O(n^2)
//. S.C -> O(1)
void brute(vector<int>arr) {

    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) cnt++;
        }
    }

    cout << cnt << endl;
}

//* Method - II (Optimal Solution)
// Here the solution is done without the Global variable which makes the code slightly complex, but this is what the interviewer would like. We can do it using global varibel, in that case all the mergeSort funciton would be of void type and simply the global variable would keep the count of the inversions

// int countInversion = 0; //! Taking a Global variable

//. T.C -> O(n*log(n))
//. S.C -> O(n), for the temporary array used in the merge sort
//! Note: Here, we are distorting the input array, if we don't want that we can just make a copy of that array and perform all the actions
int merge(vector<int>& arr, int low, int mid, int high) {

    int left = low;
    int right = mid+1;

    vector<int>temp;

    int countInversion = 0;

    while(left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }

        //! Left is greater than Right. This is the required step
        else {
            temp.push_back(arr[right]);
            right++;

            //! If one element in left is greater than a element in right, then all the element in the left portion till end would be greater than the element in the right
            countInversion += (mid - left + 1); 
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int>& arr, int low, int high) {

    int countInversion = 0;
    if (low >= high) return countInversion;

    int mid = (low+high)/2;

    countInversion += mergeSort(arr, low, mid);
    countInversion += mergeSort(arr, mid+1, high);

    countInversion += merge(arr, low, mid, high);

    return countInversion;

}


int optimalSolution(vector<int>& arr) {

    return mergeSort(arr, 0, arr.size()-1);


}