#include <bits/stdc++.h>
using namespace std;

void findMaximumConsecutiveOnes(int n, int arr[]) {
    int maxi = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            cnt++;
            maxi = max(cnt, maxi);
        }

        else {
            cnt = 0;
        }
    }

    cout << maxi << endl;
}
