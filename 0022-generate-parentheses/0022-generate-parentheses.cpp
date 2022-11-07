class Solution {
public:
    void f(string ds, int open, int close, int n, vector<string>& ans)
    {
        if(close==n)
        {
            ans.push_back(ds);
            return;
        }
        if(open<n)
        {
            f(ds+'(',open+1,close,n,ans);
        }
        if(open>close)
        {
            f(ds+')',open,close+1,n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;
        f(ds,0,0,n,ans);
        return ans;
    }
};