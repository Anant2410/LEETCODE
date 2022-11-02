class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it: t)
        {
            mp[it]++;
        }
        int count = mp.size();
        int ans = INT_MAX;
        int i=0,j=0,start=0;
        
        while(j<s.size())
        {
            mp[s[j]]--;
            if(mp[s[j]] == 0)
            {
                count--;
            }
            
            if(count==0)
            {
                while(count==0)
                {
                    if(ans > j-i+1)
                    {
                        ans = j-i+1;
                        start= i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]> 0)
                    {
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans != INT_MAX)
            return s.substr(start,ans);
        return "";
    }
};