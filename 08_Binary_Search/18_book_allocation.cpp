#include <bits/stdc++.h>
using namespace std;

// For everyone to hold atleast one book, we have to allocate atleast each M pages (M is the maximum element in the array), if we allocate lower than this, then some won't be able to hold even any book. Hence the minimum answer would be the largest book and the maximum would be the total sum
// Also, we want all the books to be distrubted only among the given number of students. We don't want more or less students, we want exactly the given number of students

// Returns the total number of students amongst which the maxPages, which is the max pages a student can hold
int totalStudents (vector<int>arr, int maxPages) {

    int student = 1;
    int pageCnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pageCnt + arr[i] <= maxPages) {
            pageCnt += arr[i];
        }
        else {

            student++;
            pageCnt = arr[i];

        }
    }

    return student;

}

//* Method - I (Brute Force)
//. T.C -> O((sum - max + 1) * n)
int brute(vector<int>pages, int k) {
    int low = INT_MIN, high = 0;
    for (auto elem : pages) {
        low = max(low, elem);
        high += elem;
    }

    for (int i = low; i <= high; i++) {
        int cntStudents = totalStudents(pages, i);
        if (cntStudents == k) return i;
    }

    return -1;
}

//* Method - II (Optimal Solution)

//. T.C -> O(log(sum - max + 1) * n)
//. S.C -> O(1)
int optimal(vector<int> pages, int k) {

    // to handle the edge case, when total books is less than the students
    if (k > pages.size()) return -1;

    int low = INT_MIN, high = 0;
    for (auto elem : pages) {
        low = max(low, elem);
        high += elem;
    }

    while (low <= high) {

        int mid = (low + high)/2;

        int cntStudents = totalStudents(pages, mid);

        if (cntStudents <= k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
    
}