class Solution {
public:
    bool checkValidString(string s) {
        int lower=0,upper=0;
        for(auto it: s)
        {
            if(it=='(')
            {
                lower++;
                upper++;
            }
            else if(it==')')
            {
                lower--;
                upper--;
            }
            else
            {
                lower--;
                upper++;
            }
            lower = max(lower,0);
            if(upper<0)
                return false;
        }
        return lower==0;
    }
};