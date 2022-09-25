class Solution {
public:
    int beautySum(string s) {
        int  ans = 0;
        unordered_map<char,int> mp;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            mp.clear();
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                int maxi = INT_MIN,mini = INT_MAX;
                
                for(auto it: mp)
                {
                    maxi = max(maxi, it.second);
                    mini = min(mini,it.second);
                }
                ans += maxi-mini;
            }
        }
        return ans;
    }
};