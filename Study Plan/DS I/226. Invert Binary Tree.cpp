/*Given the root of a binary tree, invert the tree, and return its root.

 
Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return nullptr; }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node->left) { q.push(node->left); }
            if (node->right) { q.push(node->right); }
            swap(node->left, node->right);
        }
        return root;
    }
};
