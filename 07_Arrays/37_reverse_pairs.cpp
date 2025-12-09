#include <bits/stdc++.h>
using namespace std;

// Problem: Find all such pairs of i < j, such that arr[i] > 2*arr[j]

//! Note: Dry-run and see we just can simply add a condition in merge sort for this. Try to dry run, it won't work with that approach of count inversion

//* Method - I (Brute Force)
// Generate all the possible pairs and check how many pass the given condition
//. T.C -> O(n^2)
//. S.C -> O(1)



//* Method - II (Optimal Solution)
//. T.C -> O(log(n) + (n + n)) for the total solution

int reversePairs = 0; //! Global Variable

void countPairsFirstSolution(vector<int>& arr, int low, int mid, int high) {

    int right = mid+1;

    for (int i = low; i <= mid; i++) {

        while (right <= high && arr[i] > 2*arr[right]) {
            right++;
        }

        reversePairs += (right - (mid+1)); 

    }



}

void mergeFirstSolution(vector<int>& arr, int low, int mid, int high) {

    int left = low;
    int right = mid+1;

    vector<int>temp;

    while(left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
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

void mergeSortFirstSolution(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = (low+high)/2;

    mergeSortFirstSolution(arr, low, mid);
    mergeSortFirstSolution(arr, mid+1, high);

    //! This is to perform that extra step to calculate total pairs in between left and right sorted portion of the array
    countPairsFirstSolution(arr, low, mid, high);

    mergeFirstSolution(arr, low, mid, high);

}

int optimalSolution(vector<int>arr) {

    mergeSortFirstSolution(arr, 0, arr.size() - 1);

    return reversePairs;

}


//* Method - II.V (Optimal Solution without the Global Variable)
//. T.C -> O(log(n) + (n + n)) for the total solution, log(n) for divinding, n for merging and n for extra step (countPairs) => O(2*n*log(n))
//. S.C -> O(n) due to merge sort. Also note we are distorting the input array here, we can make a copy of the input array and then make the changes to that to prevent distortion

int countPairs(vector<int>& arr, int low, int mid, int high) {

    int right = mid+1;
    int cnt = 0;

    for (int i = low; i <= mid; i++) {

        while (right <= high && arr[i] > 2*arr[right]) {
            right++;
        }

        cnt += (right - (mid+1)); 

    }

    return cnt;

}

void merge(vector<int>& arr, int low, int mid, int high) {

    int left = low;
    int right = mid+1;

    vector<int>temp;

    while(left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
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

    int cnt = 0;

    if (low >= high) return cnt;

    int mid = (low+high)/2;

    cnt += mergeSort(arr, low, mid); // first portion calculation (past)
    cnt += mergeSort(arr, mid+1, high); // second portion calculation (past)

    //! This is to perform that extra step to calculate total pairs in between left and right sorted portion of the array
    cnt += countPairs(arr, low, mid, high); // merging them and now getting the calculation (present)

    merge(arr, low, mid, high);

    return cnt;

}

int optimalSolutionWithoutGlobalVariable(vector<int>arr) {

    return mergeSort(arr, 0, arr.size() - 1);

}
