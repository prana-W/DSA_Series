#include <bits/stdc++.h>
using namespace std;

// Problem: Rearrange the array in any manner and form a consecutive sequence of elements of any length. We have to return the maximum length of such a consequtive sequence that we can obtain after any rearrangement of the array. Note: We don't need to choose contigious elements

//* Method - I (Extreme Brute Force)

// Iterate thorugh each element and inside each iteration, keep on iterating the array as we keep on finding the next element 

bool ls(int arr[], int tar, int n) {

    bool isFound = false;

    for (int i = 0; i < n; i++) {

        if (arr[i] == tar) {
            isFound = true;
            break;
        }

    }

    return isFound;
}

//. T.C -> O(n^3), nearly
//. S.C -> O(1), as no extra space
void brute(int n, int arr[]) {
    int ans = 1; // The longest sequence would be always >= 1

    //. n times outer loop
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        int cnt = 1;

        // We do a linear search for curr+1 element and if found we update the curr and increaset the cnt.

        //. n times inner loop
        //. n iterations inside each ls() function
        while (ls(arr, curr+1, n)) {
            curr = curr+1;
            cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
}


//* Method - II (Better Solution)

// First sort the given array and then try to find if consecurtive sequence exists or not

// But, here we are distorting the array, so the interviewever might not like this

//. T.C -> O(nlogn + n)
void betterSolution(int n, int arr[]) {

    int ans = 1, cnt = 0, lastSmaller = INT_MIN;

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {

        if (arr[i] - 1 == lastSmaller) {
            cnt++;
            lastSmaller = arr[i];
        }

        else if (arr[i] != lastSmaller) {
            cnt = 1; // reset the counter
            lastSmaller = arr[i];
        }

        ans = max(ans, cnt);

    }


    cout << ans << endl;
}

//* Method - III (Optimal Solution) 

//. T.C -> O(3*n)
//. S.C -> O(n)

// BUt if somehow collisions occur moore, finding the elemenet might take 'n' time complexity, instead of O(1)
int optimalSolution (int n, int arr[]) {

    if (n == 0) return 0;

    int ans = 1;

    unordered_set<int>st;

    // O(n)
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    // O(2*n)
    for (auto elem : st) {
        // If elem-1 doesn't exist in the set, then keep on searching
        if (st.find(elem - 1) == st.end()) {

            int cnt = 1;
            int curr = elem;

            // This only takes time when there is no elem-1, hence it doesn't take n time complexity, rather overall (in total of all the outer iteration) it just takes about 'n' time which is added to the n outer iterations
            while (st.find(curr + 1) != st.end()) {

                curr++;
                cnt++;

            }

            ans = max(ans, cnt);
        }
    }

    return ans;
}