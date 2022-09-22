class Solution {
public:
    string removeOuterParentheses(string s) {
        int x=0;
        string ans;
        for(auto it: s)
        {
            if(it=='(')
            {
                if(x>0)
                {
                    ans += '(';
                }
                x++;
            }
            else
            {
                if(x>1)
                {
                    ans += ')';
                }
                x--;
            }
        }
        return ans;
    }
};