class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>> maxh;
        
        for(auto it: mp)
        {
            maxh.push({-it.second,it.first});
        }
        while(!maxh.empty())
        {
            int x = maxh.top().first;
            for(int i=0;i<abs(x);i++)
            {
                ans.push_back(maxh.top().second);
            }
            maxh.pop();
        }
        return ans;
    }
};