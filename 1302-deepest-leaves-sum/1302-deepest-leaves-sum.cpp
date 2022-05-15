class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>last;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>v;
            while(n--)
            {
                TreeNode* node=q.front();
                q.pop();       
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                v.push_back(node->val);
            }
            last=v;
        }
        sum=accumulate(last.begin(),last.end(),0);
        return sum;
    }
};