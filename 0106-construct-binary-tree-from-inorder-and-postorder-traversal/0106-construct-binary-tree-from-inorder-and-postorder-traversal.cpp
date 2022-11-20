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
    TreeNode* f(vector<int>& postorder, int poststart, int postend, 
               vector<int>& inorder, int instart, int inend, map<int,int>&mp)
    {
        if(poststart > postend || instart > inend)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postend]);
        int inroot = mp[node->val];
        int rem = inroot - instart;
        
        node->left = f(postorder,poststart, poststart+rem-1,inorder,instart,
                       inroot-1,mp);
        node->right = f(postorder,poststart+rem,postend-1,
                        inorder,inroot+1,inend,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode* root = f(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};