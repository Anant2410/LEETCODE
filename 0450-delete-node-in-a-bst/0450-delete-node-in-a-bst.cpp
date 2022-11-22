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
    TreeNode* find(TreeNode* root)
    {
        if(root->left==NULL)
            return root;
        
        return find(root->left);
    }
    TreeNode* fun(TreeNode* root)
    {
        if(root->left==NULL)
            return root->right;
        if(root->right ==NULL)
            return root->left;
        TreeNode* leftchild = root->left;
        TreeNode* rightchild = find(root->right);
        rightchild->left = leftchild;
        return root->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val == key)
        {
            return fun(root);
        }
        TreeNode* dummy = root;
        while(root)
        {
            if(key < root->val)
            {
                if(root->left && root->left->val ==key)
                {
                    root->left = fun(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right && root->right->val ==key)
                {
                    root->right = fun(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};