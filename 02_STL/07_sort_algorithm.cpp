#include <bits/stdc++.h>
using namespace std;

//* How to make a self-written/custom comparitor for sort function:
// It will return boolean value
// It will have two parameters, both being the type of data we are sorting

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second) return true; // if the above condition, it is correct order (so return true)
    if (p1.second > p2.second) return false; // but this order is not correct
   
// If we are at this point, it means that both of them are equal!

    if (p1.first >= p2.first) return true; // This is the correct condition/order, is second element in the pair is equal
    return false; // it means, p1.first < p2.first, so this is incorrect desired order, so false
}

void explainSort() {

    vector<int>v = {1, 5, 3, 2};
    int arr[5] = {5, 8, 1, 2, 6};

    //* Sorting in Array
    // sort(arr, arr + n); // [start,end)

    // We can also sort a particular section of a data
    // sort requires the starting and ending iterator. (ending is not included!)
    sort(v.begin(), v.end()); //* sort (to sort any data)


    sort(arr+1, arr+4); // sorts the array from second element to fourth element. Note, last iterator is excluded!! {5, 1, 2, 8, 6}n

    sort(arr, arr+5, greater<int>()); //! sort in descending order 
    // greater<int>() is the syntax


    // --------------------------------------------------------- //


    //* Sorting in our custom manner

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

    //? Example: Sort the above using the below condition:
    // sort it according to second element in ascending order, but if second element is same, then sort it according to first element but in decreasing

    sort(a, a + 3, comp); //* Here comp: self-written comparitor (a boolean comparitor) is our custom function
    // {{4, 1}, {2, 1}, {1, 2}}

}