#include <bits/stdc++.h>
using namespace std;

void explainExtra()
{

    //* __builtin_popcount() - for integers
    // Returns the number of set bits (number of ones in bit format)
    int num = 7;
    int cnt = __builtin_popcount(num); // 3

    //* __builtin_popcountll() - for long long int
    long long num2 = 165786578687;
    int cnt = __builtin_popcountll(num2); // if the number is long long

    // --------------------------------------------- //

    //* next_permutation()
    // This returns true if any permutation is left for a string and false if all permutation is completed (means the last permutation possible in a dictionary)
    //! Note: The string must be sorted initially to have all the possible permutations, else it will return false at the last permutation, without encountering the inital states.

    string s = "123";
    sort(s.begin(), s.end());
    // This prints all the possible permutations of the string (If the string already sorted)
    do
    { 
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));


    // ---------------------------------------------- //

    //* Max and Min element

    int arr[5] = {1, 10, 5, 80, -8};

    int maxi = *max_element(arr, arr + 5);
    // without * gives max elemement address (iterator) but with * gives element

    int mini = *min_element(arr, arr + 5);
    //  without * gives min elemement address ; with * gives element
}
