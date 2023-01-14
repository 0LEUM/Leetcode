/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000*/

class Solution {
public:
 void trav(TreeNode* root,vector<vector<int>>& ans,int c){
        if(root==nullptr)
        return;
        if(ans.size() == c)
        ans.push_back(vector<int>());
        ans[c].push_back(root->val);
        c++;
        trav(root->left,ans,c);
        trav(root->right,ans,c);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        trav(root,ans,0);
        return ans;
    }
};
