#include <iostream>
#include <utility>
using namespace std;

// * Pair: container to store two data_types
//? Part of utility lbrary
void explainPairs() {
  pair<int, int> p = {1, 3};
  cout << p.first << " " << p.second;

  pair<int, pair<int, int>> q = {1, {3, 4}};

  cout << q.first << " " << q.second.second << " " << q.second.first;

  pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}}; // This array has three elements

  cout << arr[1].second;
}
