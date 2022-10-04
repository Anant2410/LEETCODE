class Solution {
public:
    bool pal(string s, int st, int end)
    {
        while(st<=end)
        {
            if(s[st++] != s[end--])
                return false;
        }
        return true;
    }
    void f(int i, string s, vector<vector<string>>& ans, vector<string>& ds)
    {
        if(i==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(pal(s,i,j))
            {
                ds.push_back(s.substr(i,j-i+1));
                f(j+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        f(0,s,ans,ds);
        return ans;
    }
};