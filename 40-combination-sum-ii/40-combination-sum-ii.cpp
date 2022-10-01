class Solution {
public:
    void f(int i, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j] > target) break;
            if(j>i && candidates[j] == candidates[j-1]) continue;
            ds.push_back(candidates[j]);
            f(j+1,candidates,target-candidates[j],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,candidates,target,ans,ds);
        return ans;
    }
};