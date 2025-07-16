#include <bits/stdc++.h>
using namespace std;

/*
    # C++ STL divided into 4 types:
    1. Algorithms
    2. Containers ***
    3. Functions
    4. Iterators ***
*/






/*
    ** Set Container **
    -> It stores everything in the sorted order
    -> Stores unique // *UNIQUE

*/
void explainSet() // O(lon n)
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
    auto it = st.find(3); // treturs to the iterator which point to the 3

    // {1, 2, 3, 4, 5}
    auto it = st.find(6); // if an element is not here in the set ,
    // it will always return st.end(); --> an iterator which point to right after the end

    // {1,4,5}
    st.erase(5); // erases 5 // takes logarithmic time

    int cnt = st.count(1); // if 1 occerence it will gives 1 nor 0

    auto it = st.find(3);
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

void explainMap()
{
    // * map stores unique keys in sorted order

    map<int, int> mpp; // {key,value}

    map<int, pair<int, int>> mpp; // here key is integer, value is 2 integer

    map<pair<int, int>, int> mpp; // here key is 2 integer, value is 1 integer

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert({2, 4});

    // mpp[{2, 3}] = 10;

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    // cout << *(it).second;

    auto it = mpp.find(5); // if 5 not there it point to nothing but mpp.end();
                           // .end() means after the mpp

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase(), swap(), size(), empty(), are same as above
}

void explainMultimap()
{
    // everything is same as map, only it can store multiple keys
    // only mpp[key] can not be used here
}

void explainUnorderedMap()
{
    // unique keys but not stored
    // same as set and unordered_Set differnce.
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    // they are same

    if (p1.first > p2.first)
        return true;
    return false;
}

void explainExtra()
{

    sort(a, a + n); // [start,end)
    sort(v.begin(), v.end());

    sort(a + 2, a + 4); // we can sort a portion

    sort(a, a + n, greater<int>); // sort in descending order

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in decreasing

    sort(a, a + n, comp);

    int num = 7;
    int cnt = __builtin_popcount(); // returns 2 , the number of set bits
                                    // 1 1 0

    long long num = 165786578687;
    int cnt = __builtin_popcountll(); // if the number is long long

    string s = "123";
    sort(s.begin(), s.end()); // always start from sorted

    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a, a + n);
    // without * gives max elemement address ; with * gives element

    int mini = *min_element(a, a + n);
    //  without * gives min elemement address ; with * gives element
}

int main()
{
    // explainPairs();
    // explainVectors();

    return 0;
}

// its enough :)