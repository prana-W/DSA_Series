#include <bits/stdc++.h>
using namespace std;

int linearSearch(int n, int arr[], int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;   
}