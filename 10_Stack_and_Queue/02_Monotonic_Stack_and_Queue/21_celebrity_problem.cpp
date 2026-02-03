#include <bits/stdc++.h>
using namespace std;

//! In all the below solution, I have assumed that the celebrity knows himself

//* Method - I (Brute Force)

// Use a nested loop. First check if the person is Popular (if everyone know him), then cofirm if he knows only himself, if he knows anybody else other than him then he is just popular and not a celeb.

//. T.C -> O(2*n^2)
//. S.C -> O(1)
int bruteForce(vector<vector<int>>& mat) {
        
        int n = mat.size();

        int ans = -1;
        
        for (int col = 0; col < n; col++) {
            
            // Finding Popular Person
            
            bool popular = true;
            for (int row = 0; row < n; row++) {
                if (mat[row][col] == 0) {
                    popular = false;
                    break;
                }
            }
            
            // Checking of Popular person is Celeb
            if (popular) {
                bool isCeleb = true;
                for (int i = 0; i < n; i++) {
                    
                    if (i != col && mat[col][i] == 1) {
                        isCeleb = false;
                        break;
                    }
                    
                }
                
                if (isCeleb) {
                    ans = col;
                    break;
                }
            }
            
        }
        
        
        return ans;
        
}

//* Method - II (Optimal Solution)

// Keep two row pointers, 'top' and 'bottom'. 

// If top knows bottom, or bottom doesn't know top, then top can't be celeb. Also, if bottom knows top, or top doesn't know bottom, then bottom can't be celeb. At then end, 'bottom' could be our celeb, but check that manually for confirmation

//. T.C -> O(3n)
//. S.C -> O(1)
int optimalApproach(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int top = 0, bottom = n-1;
        
        while (top <= bottom) {
            
            // If top knows bottom, or bottom doesn't know top, then top can't be celeb
            if (mat[top][bottom] == 1 || mat[bottom][top] == 0) {
                top++;
            }
            
            // if bottom knows top, or top doesn't know bottom, then bottom can't be celeb
            else {
                bottom--;
            }
            
        }
        
        // 'bottom' is the candidate for celeb. Check it manually to confirm in row and col
        for (int col = 0; col < n; col++) {
            if (bottom != col && mat[bottom][col] == 1) return -1;
        }
        for (int row = 0; row < n; row++) {
            if (mat[row][bottom] != 1) return -1;
        }
        
        return bottom;
        
}