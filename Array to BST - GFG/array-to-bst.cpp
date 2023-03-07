//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    struct TreeNode {
	    int val;
        TreeNode *left;
	    TreeNode *right;
	    TreeNode() : val(0), left(nullptr), right(nullptr) {}
	    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};
	void preorder(TreeNode* root, vector<int>& ans)
	{
	    if(root==NULL) return ;
	    ans.push_back(root->val);
	    preorder(root->left,ans);
	    preorder(root->right,ans);
	}
	TreeNode* insert(TreeNode* root, int val)
	{
	    if(!root)
	    {
	        root = new TreeNode(val);
	        return root;
	    }
	    
	    if(root->val > val) return insert(root->left,val);
	    return insert(root->right,val);
	}
	TreeNode* fun(TreeNode* root, vector<int>& nums, int l, int r)
	{
	    int mid = l + (r-l)/2;
	    root = insert(root,nums[mid]);
	    if(mid!=l)
	    {
	        root->left = fun(root,nums,l,mid-1);
	    }
	    if(mid!=r)
	    {
	        root->right = fun(root,nums,mid+1,r);
	    }
	    return root;
	}
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        TreeNode* root = fun(NULL,nums,0,nums.size()-1);
        preorder(root,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends