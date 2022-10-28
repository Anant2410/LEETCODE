class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(),i=0,j=0;
        int ans = -1,maxi = 0;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if((j-i+1) - maxi > k)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};