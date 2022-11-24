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
    void f(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL) return;
        f(root->left,ans);
        ans.push_back(root->val);
        f(root->right,ans);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        f(root,ans);
        int low = 0, high = ans.size()-1;
        while(low<high)
        {
            if(ans[low] + ans[high] == k)
                return true;
            else if(ans[low] + ans[high] > k)
                high--;
            else
                low++;
        }
        return false;
    }
};