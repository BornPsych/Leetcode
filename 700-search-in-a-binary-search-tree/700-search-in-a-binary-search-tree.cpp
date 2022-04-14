/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* x = NULL;
    void preorder(TreeNode* root, int val){
        if(root->val==val)x= root;
        if(root->left!=NULL)preorder(root->left,val);
        if(root->right!=NULL)preorder(root->right,val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
         preorder(root,val);
         return x;
    }
};