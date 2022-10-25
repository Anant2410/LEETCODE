class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char> st;
        for(int i=0;i<num.size();i++)
        {
           while(!st.empty() && k > 0 && st.top() > num[i])
           {
               st.pop();
               k--;
           }
            st.push(num[i]);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int d=0;
        while(d<ans.size() && ans[d]=='0') d++;
        string res = "";
        for(int i=d;i<ans.size();i++)
        {
            res+= ans[i];
        }
        if(res.size()==0)
        {
            res = "0";
        }
        return res;
    }
};