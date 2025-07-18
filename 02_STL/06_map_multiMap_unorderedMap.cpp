#include <bits/stdc++.h>
using namespace std;

//! Works in O(log n)
void explainMap()
{
    // * map stores unique keys in sorted order (similar to set)
    // keys are unique, but values can be duplicate
    // key and value can be of any data type (double, integer, pair, anythhing!)

    map<int, int> mpp; // {key,value}

    map<int, pair<int, int>> mpp2; // here key is integer, value is a pair of two integers

    map<pair<int, int>, int> mpp3; // here key is a pair of two integers, value is one integer

    mpp[1] = 2; // It means for a key 1, store the value 2     
    mpp.emplace(3, 1); // Same as above
    mpp.insert({2, 4}); // Same as above

    mpp3 [{2, 3}] = 10; // key is a pair of integers and the value is a single integer 

    //? for-each loop
    // 'it' is the element (consisting of key, value pair)
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl; //it.first is the key and it.second is the value (everything is stored in a sorted order of key)
    }

    cout << mpp[1] << endl; // Returns the value for key 1
    cout << mpp[5] << endl; //! Returns the value for key 5 (since not exists, so gives 0, representing null)

    auto it2 = mpp.find(3); // Returns an iterator for the key-value pair
    cout << (*it2).second << endl; // This returns the value of the element. *it2 returns the map element from the address

    auto it3 = mpp.find(5); //! if 5 not there it point to mpp.end(); .end() means after the mpp

    auto it4 = mpp.lower_bound(2);
    auto it5 = mpp.upper_bound(3);

    // erase(), swap(), size(), empty(), are same as above
}

void explainMultimap()
{
    //* everything is same as map, only it can store multiple keys
    //! only mpp[key] can not be used here
}

//! Works in O(1) almost always and in the worst case happens in O(n)
void explainUnorderedMap() {
    //* unique keys but not sorted
}

int main() {
    explainMap();
}