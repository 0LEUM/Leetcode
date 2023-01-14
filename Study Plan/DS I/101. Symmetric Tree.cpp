/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 
Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> bfs;
        q.push(root);
        while(!q.empty()){
            int a=q.size();
            vector<int> arr;
            while(a--){
                TreeNode* t=q.front();
                if(t->left!=NULL){
                    q.push(t->left);
                    arr.push_back(t->left->val);
                }else{
                    arr.push_back(-101);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                    arr.push_back(t->right->val);
                }else{
                    arr.push_back(-101);
                }
                q.pop();
            }
            bfs.push_back(arr);
        }
        for(int i=0;i<bfs.size();i++){
            int a=bfs[i].size();
            int s=a/2 -1,e=a/2;
            while(s>-1 && e<a){
                if(bfs[i][s]!=bfs[i][e]) return 0;
                s--;
                e++;
            }
        }
        return 1;
    }
};
