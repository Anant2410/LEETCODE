class Solution {
public:
    int possible(vector<int>& ds)
    {
        int sum=0;
        for(auto it: ds)
        {
            sum += it;
        }
        return sum;
    }
    void f(int i, int k , int n , vector<vector<int>>& ans, vector<int>& ds)
    {
        if(k==0)
        {
            if(possible(ds) == n)
                ans.push_back(ds);
            return;
        }
        if(i>9) return;
        ds.push_back(i);
        f(i+1,k-1,n,ans,ds);
        ds.pop_back();
        f(i+1,k,n,ans,ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(1,k,n,ans,ds);
        return ans;
    }
};