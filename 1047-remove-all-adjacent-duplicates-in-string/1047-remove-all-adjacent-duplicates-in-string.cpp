class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto it: s)
        {
            if(st.empty() || st.top()!=it)
            {
                st.push(it);
            }
            else if(st.top()==it)
            {
                st.pop();
            }
        }
        string ans ="";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};