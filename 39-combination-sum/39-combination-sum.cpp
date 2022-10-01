class Solution {
public:
    void f(int index, vector<int>& candidate, int target, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(index==candidate.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidate[index]<= target)
        {
            ds.push_back(candidate[index]);
            f(index,candidate,target-candidate[index], ans,ds);
            ds.pop_back();
        }
        f(index+1,candidate,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,candidates,target,ans,ds);
        return ans;
    }
};