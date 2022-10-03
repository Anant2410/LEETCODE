class Solution {
public:
    void f(string s, int n, int open, int close, vector<string>& ans)
    {
        if(close==n)
        {
            ans.push_back(s);
            return;
        }
        else
        {
            if(open < n)
            {
                f(s+'(',n,open+1,close,ans);
            }
            if(open > close)
            {
                f(s+')',n,open,close+1,ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n>0)
        {
            f("",n,0,0,ans);
        }
        return ans;
    }
};