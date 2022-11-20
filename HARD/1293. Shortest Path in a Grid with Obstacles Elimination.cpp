/*You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 
Example 1:

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0*/

class Solution 
{
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        // [1] this check significantly improves runtime, i.e.,
        //    we can use path [0,0] -> [0,n-1] -> [m-1,n-1]
        if (k >= m + n - 2) return m + n - 2;
        
        // [2] we use deque to store and update a BFS state that is
        //    (x, y, obstacles we can destroy, steps done so far)
        deque<vector<int>> dq;
        dq.push_back({0,0,k,0});
        // [3] we also keep track of visited cells
        set<vector<int>> seen;
        
        vector<pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty())
        {
            vector<int> p = dq.front(); dq.pop_front();
            int i = p[0], j = p[1], k = p[2], s = p[3];
            // [4] successfully reached lower right corner
            if (i == m-1 && j == n-1) return s;
            
            // [5] scan all possible directions
            for (auto d : dirs)
            {
                int ii = i + d.first, jj = j + d.second;
                // [6] check boundaries and obstacles
                if (0 <= ii && ii < m && 0 <= jj && jj < n && k >= grid[ii][jj])
                {
                    // [7] make (and remember) a step
                    vector<int> step = {ii, jj, k-grid[ii][jj]};
                    if (seen.count(step) == 0) // in C++20, there is 'map::contains()'
                    {
                        seen.insert(step);
                        step.push_back(s+1);
                        dq.push_back(step);
                    }
                }
            }
        }
        
        // [8] failed to reach lower right corner
        return -1;
    }
};
