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
    void fun(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL)return;
        fun(root->left,ans);
        ans.push_back(root->val);
        fun(root->right,ans);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        fun(root,ans);
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i] >= ans[i+1])
                return false;
        }
        return true;
    }
};