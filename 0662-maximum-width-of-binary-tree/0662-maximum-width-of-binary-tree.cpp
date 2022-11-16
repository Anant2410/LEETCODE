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
    int widthOfBinaryTree(TreeNode* root) {
        int ans= 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int maxi = INT_MIN, mini = INT_MAX;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                unsigned int index = it.second;
                maxi = max(maxi,(int)index);
                mini = min(mini,(int)index);
                
                if(node->left)
                {
                    q.push({node->left,2*index+1});
                }
                if(node->right)
                {
                    q.push({node->right,2*index+2});
                }
            }
            ans = max(ans,maxi-mini+1);
        }
        return ans;
    }
};