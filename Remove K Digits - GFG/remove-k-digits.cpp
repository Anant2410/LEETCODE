//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        string res = "";
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            while(!st.empty() && k>0 && st.top() > s[i])
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int d=0;
        while(d<res.size() && res[d] == '0')d++;
        string ans = "";
        for(int i=d;i<res.size();i++)
        {
            ans += res[i];
        }
        if(ans.size() ==0)
        {
            ans = "0";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends