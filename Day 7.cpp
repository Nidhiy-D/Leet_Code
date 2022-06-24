/*
Question 1

733. Flood Fill
Easy

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n


*/

//Solution

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        fillCell(image, image[sr][sc], newColor, sr, sc);
        return image;
    }
    
    void fillCell(vector<vector<int>>& image, int initialColor, int newColor, int x, int y) {
        int n = image.size(), m = image[0].size();
        
        if(image[x][y] == initialColor) {
            if (initialColor == newColor) return;
            image[x][y] = newColor;  
            if (x+1<n) fillCell(image, initialColor, newColor, x+1, y);
            if (x-1>=0) fillCell(image, initialColor, newColor, x-1, y);
            if (y+1<m) fillCell(image, initialColor, newColor, x, y+1);
            if (y-1>=0) fillCell(image, initialColor, newColor, x, y-1);
        }
        return;
    }
};

///////////////////////////////////////////////////////

/*
Question 2

695. Max Area of Island
Medium

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

//Solution
class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
            return 0;
        grid[i][j] = 0;
        int count = 1;
        count += dfs(i+1,j,grid);
        count += dfs(i-1,j,grid);
        count += dfs(i,j+1,grid);
        count += dfs(i,j-1,grid);
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)
                    ans = max(ans,dfs(i,j,grid));
            }
        }
        return ans;
    }
};
