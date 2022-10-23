class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        map<int,int> mp;
        set<int>st;
        for(auto it: nums)
        {
            mp[it]++;
            st.insert(it);
        }
        for(auto it: mp)
        {
            if(it.second>1)
            {
                ans[0] = it.first;
            }
        }
        int sum = 0;
        for(auto it: st)
        {
            sum += it;
        }
        int n = nums.size();
        int res = (n*(n+1))/2;
        ans[1] = res - sum;
        
        return ans;
    }
};