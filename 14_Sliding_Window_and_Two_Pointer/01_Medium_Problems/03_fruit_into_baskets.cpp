#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Treat all the index as starting point one by one, and then try to find the longest length from there till we encounter more than 2 elements

//. T.C -> O(n^2)
//. S.C -> O(1), size of set doesn't grow with input
int totalFruit(vector<int>& fruits) {

    int n = fruits.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {

        int j = i;
        set<int>st;

        while (j < n) {

            st.insert(fruits[j]);
            if(st.size() == 3) break;

            j++;

        }

        ans = max(ans, j-i);
    }

    return ans;        
}

//* Method - II (Better Solution)
// Make two pointers, i and j. i represents the picking up point, or the starting point from where we start picking up the fruit and j is the incoming fruit.
// Try to put fruits till a new fruit type is encountered and both basket has some fruit, in this case try to move i to the right till one of the basket becomes emepty, then put in the new fruit

//. T.C -> O(2n)
//. S.C -> O(1), size of map doesn't grow with input
int better(vector<int>& fruits) {

    int i = 0; // Pickup Point
    int j = 0; // Incoming fruit

    int n =  fruits.size(), ans = 0, first = fruits[j], second = fruits[j];
    unordered_map<int, int>mp; // O(2) in worst case

    while (j < n) {
        
        // If the incoming fruit is not present and both basket is full
        if(mp.find(fruits[j]) == mp.end() && mp.size() == 2) {
            
            // Try to move the left pointer, till any basket becomes empty for the incoming new fruit type
            while(i < n && mp.size() == 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

        }

        // Include the incoming fruit
        mp[fruits[j]]++;
        j++;

        ans = max(ans, j-i);
    }

    return ans;
        
}

//* Method - III (Optimal Solution)
// Instead of using another data structure, we use five new variable, f1 and f2 represents the fruit type stored in basket one and two and f1Index and f2Index represent the last index of that particular fruit type during the iteration and size reperesents the basket full size. Whenever size is less than 2 and incoming fruit deosn't match neighter of the fruit type, simply put it in the -1 basket and update the size. When new fruit comes and size is already full, then remove the fruit which can be removed by moving less amount of time, that is which has smaller index and then placee the new incoming fruit in the emptied basket. Also always update f1index and f2Index and j.

//. T.C -> O(n), a single loop
//. S.C -> O(1), no new data structure used
int optimal(vector<int>& fruits) {

    int i = 0; 
    int j = 0;

    int n =  fruits.size(), ans = 0, first = fruits[j], second = fruits[j];

    // f1 and f2 are the baskets containing different fruit type and f1Index and f2Index is the last index of the fruit of that type
    int f1 = -1, f2 = -1, f1Index = 0, f2Index = 0;

    int size = 0; // Represent baskets used

    while (j < n) {

        // If both basket is not full, then bring the incoming fruit to the -1 basket and increase the size
        if (fruits[j] != f1 && fruits[j] != f2 && size < 2) {
            if (f1 == -1) f1 = fruits[j];
            else f2 = fruits[j];
            size++;
        } 

        // If both basket is full and new fruit is incoming, then put it in the basket which has the index as loest, so we have to move i by only small amount
        else if (fruits[j] != f1 && fruits[j] != f2 && size == 2) {
            if (f1Index < f2Index) {
                i = f1Index+1; // Left pointer updated, to remove the f1 fruit type
                f1 = fruits[j]; // Put the new incoming fruit in f1 
            }
            else {
                i = f2Index+1;
                f2 = fruits[j];
            }
        }

        // Updating f1Index and f2Index always
        if (fruits[j] == f1) f1Index = j;
        if (fruits[j] == f2) f2Index = j;

        j++;

        ans = max(ans, j-i);
    }

    return ans;
        
}
