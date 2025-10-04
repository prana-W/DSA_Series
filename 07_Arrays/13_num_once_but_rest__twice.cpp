#include <bits/stdc++.h>
using namespace std;

// An array with all the element appearing twice, except one element which only appear once, Find that element

//* Method - I (Brute Force)
// Pick each element one by one, and then make a second loop to iterate again in the loop, if we find another occurence of that element, then, its not the answer, else it will be the answer

//. T.C -> O(n^2)
//. S.C -> O(n)
void bruteSol(int n, int arr[]) {

  for (int i = 0; i < n; i++) {
    int tar = arr[i];
    bool flag = true;

    for (int j = 0; j < n; j++) {
      if (j == i)
        continue;

      if (arr[j] == arr[i]) {
        flag = false;
        break;
      }
    }

    if (flag == true) {
        cout << arr[i] << endl;
        break;
    }
  }
}

//* Method - II (Better Approach) 
// Hash Approach
//. T.C -> O(3*n)
//. S.C -> O(x), x is the maximum element in the array

// First, find the maximum element in the array, then using that element M, make a hash array with size M+1. Now iterate the given array and increase the count in the hash array. At the end iterate the hash array, the one with the single frequency, is the answer

// If the array has very big numbers, it is not at all feasible to hash that normally. Therefore we will use unordered_map instead

void betterHashApproach(int n, int arr[]) {
    // Find the maximum element to determine the size of the hash array

    int maxi = arr[0];

    for (int i = 0; i < n; i++) {
        maxi = max (arr[i], maxi);
    }

    int hashArr[maxi+1] = {0};

    // Filling the hash array with each occurence of any element
    for (int i = 0; i < n; i++) {
        int index = arr[i];

        hashArr[index]++;
    }

    // Determine the element with single occurence in the hashArr
    int ans = -1;
    for (int i = 0; i < maxi+1; i++) {

        if (hashArr[i] == 1) {
            ans = i;
            break;
        }

    }

    cout << ans << endl;

}


//. T.C -> O(n*log(m) + O(m)) for ordered map and O(n + m) for normal case in unorderd_map, but it could be O(n*m + m) in worst case for unordered_map, where n is the size of the array and m is the size of the map
void betterHashByMap (int n, int arr[]) {
    unordered_map<int, int>mp;

    // O(n*log(n)) for ordered map and O(n) for unordered_map in normal case (though in worst case it can be O(n^2))
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++; // O(log(m)), m is the number of keys in the map
    }

    int ans = 0;

    // O(m), where m is the size of the map. Here map size will be (n/2 + 1) as one element occurs once and the rest appears twice, so the unique elements will be (n-1)/2 + 1 or (n+1)/2 or n/2 + 1

    for (auto elem : mp) {
        if (elem.second == 1) {

            ans = elem.first;
            break;

        }
    }

    cout << ans << endl;


}

//* Method - III (Optimal Solution)

// Take the XOR of all the elements, the twice element will cancel out and the one will be the result itself

void optimalApproach (int n, int arr[]) {

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans ^= arr[i];
    }

    cout << ans << endl;
    
}
