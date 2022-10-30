class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> idx(3,-1);
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            idx[s[i] - 'a'] = i;
            ans += min(idx[0],min(idx[1],idx[2])) + 1;
        }
        return ans;
    }
};