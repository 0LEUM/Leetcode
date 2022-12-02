/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 
Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.*/

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int dirs[5] = {0, -1, 0, 1, 0};
        map<char,int> cnt;
        int m = board.size(), n = board[0].size(), l = word.size();
        
        for (char c : word) cnt[c] += 1;
        
        if (cnt[word[0]] > cnt[word[l-1]])
            reverse(word.begin(), word.end());
        
        function<bool(int,int,int)> dfs;
        dfs = [&] (int i, int j, int s) -> bool
        {
            if (s == l) return true;
            
            if (i < 0 or i >= m or j < 0 or j >= n) return false;
            if (board[i][j] != word[s])             return false;
            
            board[i][j] = '#';
            for (int d = 0; d < 4; ++d)
                if (dfs(i + dirs[d], j + dirs[d+1], s+1)) return true;
            board[i][j] = word[s];
            
            return false;
        };
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfs(i, j, 0)) return true;
        
        return false;
    }
};
