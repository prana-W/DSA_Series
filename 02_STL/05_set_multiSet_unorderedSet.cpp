#include <bits/stdc++.h>
using namespace std;



   // ** Set Container **
    //? -> It stores everything in the sorted order and in unique

void explainSet() //! O(lon n) Time Complexity
{
    set<int> st;

    st.insert(1);  // {1}
    st.emplace(2); // {1,2}
    st.insert(2);  // {1,2}
    st.insert(4);  // {1,2,4}
    st.insert(3);  // {1,2,3,4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size()
    // empty() and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); //! returs the iterator which point to the 3

    // {1, 2, 3, 4, 5}
    auto it = st.find(6); //! if an element is not here in the set, it will always return an iterator pointing st.end(); --> an iterator which point to right after the end

    // {1,4,5}
    st.erase(5); // erases 5 // takes logarithmic time

    int cnt = st.count(1); //! used to actually find if an element exists or not
    // if 1 occerence it will gives 1 nor 0
    
    st.erase(it); // it takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1,4,5} [first, last)

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does

    // This is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);
}

void explainMultiSet()
{
    // everything is same as set
    // only stores duplicate elements also

    multiset<int> ms;

    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1); // -> counts number of 1 in the multiset

    // only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(2)); // erase(start address, end address) // errase both of them

    // rest of all functions same as set
}

void explainUSet()
{                          // unordered set
    unordered_set<int> st; // everything is similar to set

    // lower_bound and upper_bound function
    // does not works, rest all functions are same
    // as above, it does not stores in any
    // particular order it has a better complexity  // O(1) ; blue moon happens in worst case O(N)
    // than set in most cases, except some when collision happens
}
