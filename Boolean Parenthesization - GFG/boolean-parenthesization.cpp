//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int>mp;
    int solve(string str, int i, int j, bool istrue)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(istrue==true) return str[i] == 'T';
            else return str[i] == 'F';
        }
        //if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
        string temp  = to_string(i);
        temp.append(" ");
        temp.append(to_string(j));
        temp.append(" ");
        temp.append(to_string(istrue));
        if(mp.count(temp))
        {
            return mp[temp];
        }
        int ans = 0;
        for(int k = i+1;k<j;k+=2)
        {
            int lt = solve(str,i,k-1,true);
            int lf = solve(str,i,k-1,false);
            int rt = solve(str,k+1,j,true);
            int rf = solve(str,k+1,j,false);
            
            if(str[k] == '&')
            {
                if(istrue == true)
                {
                    ans = (ans + lt * rt)%1003 ;
                }
                else
                {
                    ans = (ans + lt*rf + lf*rt + lf*rf)%1003;
                }
            }
            else if(str[k] == '|')
            {
                if(istrue == true) ans = (ans + lt*rt + lt*rf + lf*rt)%1003;
                else ans = (ans + lf*rf)%1003;
            }
            else if(str[k] == '^')
            {
                if(istrue == true) ans = (ans + lt*rf + lf*rt)%1003;
                else ans = (ans + lt*rt + rf*lf)%1003;
            }
        }
        return mp[temp] = ans;
    }
    int countWays(int N, string S){
        return solve(S,0,N-1,true);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends