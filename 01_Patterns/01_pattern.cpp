// https://www.naukri.com/code360/problems/ninja-and-the-star-pattern-i_6581920

#include <iostream>
using namespace std;

//* Here the boundary condition is when row is first or last or column is first or last. In all the four cases, we print the star else we don't!!

int main () {

    int n;
    cin >> n;
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) cout << "* ";

            else cout << "  ";
        }
        cout << endl;
    }

}