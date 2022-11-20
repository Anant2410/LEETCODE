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
    TreeNode* f(vector<int>&preorder,int prestart, int preend,
               vector<int>&inorder, int instart, int inend, map<int,int>&mp)
    {
        if(prestart>preend || instart > inend)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[prestart]);
        int inroot = mp[node->val];
        int rem = inroot - instart;
        node->left = f(preorder,prestart+1,prestart+rem,inorder,instart,inroot-1,mp);
        node->right = f(preorder,prestart+rem+1,preend,inorder,inroot+1,inend,mp);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        root = f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        
        return root;
    }
};