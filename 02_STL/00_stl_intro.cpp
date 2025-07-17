#include <bits/stdc++.h>
using namespace std;

/*
    # C++ STL divided into 4 types:
    1. Algorithms
    2. Containers ***
    3. Functions
    4. Iterators ***
*/

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