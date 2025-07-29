#include <bits/stdc++.h>
using namespace std;

//* Bubble Sort
// Pushes the maximum to the last by adjacent swaps

//. T.C -> O(n^2)
void bubbleSortUnOptimised(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {

    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

//. Time Complexity: O(n^2)  -> Worst, Avg
//. Best --> O(n) if sorted

// This checks if the array is swapped even once or not, if not, it means the array is already sorted
void bubbleSortOptimised(int arr[], int n) {

  for (int i = n - 1; i >= 0; i--) {

    bool isSwapped = false;

    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwapped = true;
      }
    }

    // Array already sorted
    if (!isSwapped) break;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bubbleSortUnOptimised(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

  return 0;
}
