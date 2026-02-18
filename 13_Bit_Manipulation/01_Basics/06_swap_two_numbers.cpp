#include <bits/stdc++.h>
using namespace std;

//! Try without temporary variable

//. T.C -> O(1)
//. S.C -> O(1)

//* Method - I (By sum and difference)
pair<int, int> m1(int a, int b) {
        
        a = a+b;

        b = a-b;
        a = a-b;
        
        return {a, b}; 
}

//* Method - II (By product and division)
pair<int, int> m2(int a, int b) {
        
        a = a*b;

        b = a/b;
        a = a/b;
        
        return {a, b};
    
}

//* Method - III (By XOR)
pair<int, int> m3(int a, int b) {
        
        a = a^b;
        
        b = a^b;
        a = a ^ b;
        
        return {a, b};     
}