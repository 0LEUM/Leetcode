/*Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

 
Example 1:

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

Constraints:

The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104*/

/*
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    int preorder(TreeNode* root)
    {
        if(root)
        {
            int left = preorder(root->left);
            int right = preorder(root->right);
            return root->val += left + right;
        }
        return 0;
    }
    
    void helper(TreeNode* root, int whole, int& res)
    {
        if(root)
        {
            helper(root->left, whole, res);
            helper(root->right, whole, res);
            if(abs(whole - 2 * root->val) < abs(whole - 2 * res))
                res = root->val;
        }
    }
    
    int maxProduct(TreeNode* root)
    {
        int res = 0;
        int mod = 1e9 + 7;
        int whole = preorder(root);      
        helper(root, whole, res);
        long long int ret = (long long int)(((whole - res) % mod) * (long long int)(res % mod));
        return ret % mod;
    }
