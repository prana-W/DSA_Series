#include <bits/stdc++.h>
using namespace std;

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

void explainUnorderedMap() {
    // unique keys but not stored
    // same as set and unordered_Set differnce.
}
