#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// If the number is positive, check if the number doesn't has set bit at the last index at every step, till the number becomes 1

//. T.C -> O(log (n))
//. S.C -> O(1)
bool brute(int n) {

        if (n <= 0) return false;

        // Till number reaches 1
        while(n != 1) {

            // This ensures, the number is divisible by 2
            if (n&1) return false;

            n = n >> 1;
        }

        return true;
        
}


//* Method - II (Optimal Solution)

// Only the positive nuber rcan be represented as 2^x. Also for any positive number of power in terms of 2. There would only be a single set bit in the number. Hence, we can simply do n-1, this makes the set bit to 0 and the precvious all bits to 1, if we do a AND between them, it should give 0

//. T.C -> O(1)
//. S.C -> O(1)
bool optimal(int n) {

        if (n <= 0) return false;
  
        if ((n&(n-1)) == 0) return true;
        
        return false;
        
}