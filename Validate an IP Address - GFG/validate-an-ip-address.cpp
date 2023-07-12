//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int count=0;
            int n = s.size();
            for(int i=0;i<n;i++)
            {
                if(s[i] == '.') count++;
            }
            //invalid ip address
            if(count!=3) return 0;
            
            string temp = "";
            unordered_set<string> st;
            count=0;
            
            for(int i=0;i<256;i++)
            {
                st.insert(to_string(i));
            }
            
            for(int i=0;i<n;i++)
            {
                if(s[i] != '.')
                {
                    temp += s[i];
                }
                else
                {
                    if(st.count(temp))
                    {
                        count++;
                    }
                    temp="";
                }
            }
            
            if(st.count(temp))
            {
                count++;
            }
            
            if(count == 4)
            {
                return 1;
            }
            
            return 0;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends