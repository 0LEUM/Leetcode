/*You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 
Example 1:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.*/

class Solution {
public:
    int ROW, COL;
    pair<int,int> END, START;
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int helper(int x, int y, vector<vector<int>>& grid, int nOC){
        if(x < 0 || y < 0 || x >= ROW || y >= COL || grid[x][y] == -1){
            return 0;
        }
        if(make_pair(x,y) == END){
            return nOC == 0;
        }
        grid[x][y] = -1;
        
        int count = 0;
        for(auto [i, j] : dirs){
            int X = x + i, Y = y + j;
            if(END.first - X + END.second - Y <= nOC)
                count+= helper(X, Y, grid, nOC-1);
        }
        
        grid[x][y] = 0;
        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        ROW = grid.size(), COL = grid[0].size();
        int nonObstacleCount=0;
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] != -1){
                    nonObstacleCount++;
                }
                
                if(grid[i][j] == 2){
                    END = {i,j};
                }
                else if(grid[i][j] == 1){
                    START = {i, j};
                }
            }
        }
        return helper(START.first, START.second, grid, nonObstacleCount-1);
    }
};
