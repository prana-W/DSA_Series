#include <bits/stdc++.h>
using namespace std;

//* Insertion Sort

//. T.C -> Worst and Average: O(n^2)
//. Best Case: O(n)
void insertion_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j], arr[j-1]);
      j--;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  insertion_sort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
 
  return 0;
}