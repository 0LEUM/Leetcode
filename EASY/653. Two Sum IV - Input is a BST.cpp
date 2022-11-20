/*Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 
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
    vector<int> arr;            //vector to store inorder traversal elements
    void fillVec(TreeNode* root){               //recursive function to do inorder traversal of the given bst
        if(root->left) fillVec(root->left);
        arr.push_back(root->val);
        if(root->right) fillVec(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root->left==NULL && root->right==NULL) return false;          //If only one node in the tree
        else fillVec(root);
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){                //Loop for two pointer logic
            if(arr[i]+arr[j]==k) return true;
            else if(arr[i]+arr[j]<k) i+=1;
            else j-=1;
        }
        return false;
    }
