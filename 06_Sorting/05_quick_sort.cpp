/*
1. pickup a pivot & place it in it's correct position in the sorted array

Pivot can be any element, first element, last element, median or any random element as well.

2. Smaller and equal on the left and larger on the right

*/

#include <bits/stdc++.h>
using namespace std;

// Places the pivot element at its correct position and returns that index (partition index)
int partition(vector<int> &arr, int low, int high) {

  int pivot = arr[low]; // pivot can be any element. Here we have chosen it to be the first element in the portion

  int i = low;
  int j = high;

  while (i < j) {
    while (arr[i] <= pivot && i < high) {
      i++;
    }

    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }

    if (i < j) swap(arr[i], arr[j]);

  }
  swap(arr[low], arr[j]); // Final swap between the pivot element and the arr[j]

  return j; // This is the partition index
}

//* Quick Sort
// Divide and Conquer

//. T.C -> O(n log2 (n)) - Best and Average
//. O(n^2) - Worst if we end up choosing the largest or smallest element as the pivot always

//. S.C -> O(1) excluding recursive stack space
void quickSort(vector<int> &arr, int low, int high) {

  if (low >= high) return;

  int partitionIndex = partition(arr, low, high); // returns the partition index, after placing the pivot element at its correct postion

  quickSort(arr, low, partitionIndex - 1);
  quickSort(arr, partitionIndex + 1, high);

}


//! H.W: Write the same code for descending

int main() {

}