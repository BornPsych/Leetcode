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
    vector<int>num;
    void preorder(TreeNode* root){
        if(!root)return;
        num.push_back(root->val);
        if(root->left)preorder(root->left);
        if(root->right)preorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        preorder(root);
        sort(num.begin(),num.end());
        TreeNode* ans;
        if(num.size()>0)ans= new TreeNode(num[0]);
        TreeNode* temp = ans;
        for(int i=1;i<num.size();i++){
            ans->right = new TreeNode(num[i]);
            ans = ans->right;
        }
        
        return temp;
    }
};