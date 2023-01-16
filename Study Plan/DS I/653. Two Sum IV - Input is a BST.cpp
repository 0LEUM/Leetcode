/*Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 
Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105*/

class Solution {
public:
void storeInorder(TreeNode* root, vector<int> &inorder){
    if(root == NULL)
        return;
    
    storeInorder(root->left , inorder);
    inorder.push_back(root->val);
    storeInorder(root->right,inorder);
    
}
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    
    storeInorder(root,inorder);
    
    int s = 0 , e = inorder.size() -1;
    
    while( s < e ){
        if( inorder[s] + inorder[e] == k ){
            return true;
        }
        else if( inorder[s] + inorder[e] < k ){
            s++;
        }
        else{
            e--;
        }
    }
    
    return false;
}
};
