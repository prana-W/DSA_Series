#include <bits/stdc++.h>
using namespace std;

// * Selection Sort
// Select minimum and swap with its correct place

//. T.C -> O(n^2)
void selection_sort(int arr[], int n) {

  // Indexes where the swapped element will come
  for (int i = 0; i < n - 1; i++) {
    int mini = i;

    // Searching for the minimum element
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }

    // Swapping the element
    swap(arr[mini], arr[i]);
    
    // int temp = arr[mini];
    // arr[mini] = arr[i];
    // arr[i] = temp;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  selection_sort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}