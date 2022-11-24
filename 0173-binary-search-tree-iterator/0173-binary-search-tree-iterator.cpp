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
class BSTIterator {
public:
   vector<int> ans;
    int i=0;
    void f(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL) return;
        f(root->left,ans);
        ans.push_back(root->val);
        f(root->right,ans);
    }
    BSTIterator(TreeNode* root) {
       f(root,ans);
    }
    
    int next() {
        int res= ans[i];
        i++;
        return res;
    }
    
    bool hasNext() {
        if(i<ans.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */