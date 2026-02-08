#include <bits/stdc++.h>
using namespace std;

// Here we take the money and need to retunr the monehy-5 back to the customer.

// We greedily try to return back the money with 20s notes, then more left out with 10s note and then the remianing with 5s notes.

// At the end, is we still need to give out money, then return false

//. T.C -> O(n)
//. S.C -> O(1)
bool lemonadeChange(vector<int>& bills) {

    // Notes of each denomination
    int fives = 0;
    int tens = 0;
    int twenties = 0;

    for (int i = 0; i < bills.size(); i++) {
        int amount = bills[i];

        // Money that needs to be returned back
        int returnedAmount = bills[i] - 5;

        // Try to give back twenties as mmuch as possible
        if (twenties) {
            int returnedBackNotes = min(twenties, returnedAmount/20);

            returnedAmount -= returnedBackNotes*20;
            twenties -= returnedBackNotes;
        }
        if (tens) {
            int returnedBackNotes = min(tens, returnedAmount/10);

            returnedAmount -= returnedBackNotes*10;
            tens -= returnedBackNotes;
        }
        if (fives) {
            int returnedBackNotes = min(fives, returnedAmount/5);

            returnedAmount -= returnedBackNotes*5;
            fives -= returnedBackNotes;
        }

        // If there is still some money to be given out, then return false
        if (returnedAmount) return false;

        if (bills[i] == 5) fives++;
        else if (bills[i] == 10) tens++;
        else twenties++;
    }

    return true;
        
}