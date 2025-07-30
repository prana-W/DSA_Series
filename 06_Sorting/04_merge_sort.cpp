#include <bits/stdc++.h>
using namespace std;

// Merge two sorted arrays 
void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;
  // [low...mid] -> first hypothetical portion
  //[mid+1...high] -> second hypothetical portion

  int left = low; // initial index of first portion
  int right = mid + 1; // initial index of second portion

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
 
  // when all the elements are exhausted in second portion
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }

  // when all the elements are exhausted in first portion
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  // Replacing the the values of arr from index low to high with the values of temp from 0 to high-low index
  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }

}

//* Merge Sort
// Divide and Merge
// Sorts and merges the array

//. T.C -> O(n * log2(n))
//. S.C -> O(n)
void mergeSort(vector<int> &arr, int low, int high) {

  if (low >= high) return; // Base case (when the hypothetical portion has a single element)

  int mid = (low + high) / 2;
 
  mergeSort(arr, low, mid); // sort the left portion
  mergeSort(arr, mid + 1, high); // sort the right portion

  merge(arr, low, mid, high); // merge the two sorted portions
}

int main() {

}