class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it: mp)
        {
            if(it.second) return false;
        }
        return true;
    }
};