#include <bits/stdc++.h>
using namespace std;

// Just use DFS recursive approach, to paint all the neighboouring pixels to newColour that are equal to oldColor

//. T.C -> O(n*m)
//. S.C -> O(n*m), recurisve stack space

void dfs(int sr, int sc, int newColor, int oldColor, vector<vector<int>>& image) {

    // Checking for out of bounds condition, and if curr color is equal to old color and if already equal to newColor (targetColor)
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor || image[sr][sc] == newColor) return;

    image[sr][sc] = newColor;

    // Solving for each direction
    dfs(sr, sc+1, newColor, oldColor, image);
    dfs(sr, sc-1, newColor, oldColor, image);
    dfs(sr+1, sc, newColor, oldColor, image);
    dfs(sr-1, sc, newColor, oldColor, image);

}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    dfs(sr, sc, color, image[sr][sc], image);

    return image;
    
}