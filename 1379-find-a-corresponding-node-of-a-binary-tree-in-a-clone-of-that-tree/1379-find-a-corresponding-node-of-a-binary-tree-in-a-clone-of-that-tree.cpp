class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!target||!original||!cloned)
        return NULL;
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty())
        {
            TreeNode* ele=q.front();
            q.pop();
            if(ele->val==target->val)
            return ele;
            if(ele->left)
            q.push(ele->left);
            if(ele->right)
            q.push(ele->right);
        }
        return NULL;
    }
};