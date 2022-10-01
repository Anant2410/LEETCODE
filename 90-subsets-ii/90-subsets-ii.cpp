class Solution {
public:
    void f(int i, vector<int>& nums, vector<vector<int>>&ans, vector<int>& ds)
    {
        ans.push_back(ds);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j] == nums[j-1])
            {
                continue;
            }
                ds.push_back(nums[j]);
                f(j+1,nums,ans,ds);
                ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,nums,ans,ds);
        return ans;
    }
};