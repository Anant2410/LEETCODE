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
    int fun(TreeNode* root)
    {
        int ans = 0;
        while(root)
        {
            ans++;
            root = root->right;
        }
        return ans;
    }
    int f(TreeNode* root)
    {
        int ans = 0;
        while(root)
        {
            ans++;
            root = root->left;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        int l = f(root);
        int r = fun(root);
        
        if(l==r)
        {
            return pow(2,l) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};