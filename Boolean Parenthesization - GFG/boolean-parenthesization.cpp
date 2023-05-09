//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int dp[201][201][2];
    int f(string str, int i, int j, bool flag)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(flag==true) return str[i] == 'T';
            else return str[i] == 'F';
        }
        if(dp[i][j][flag] != -1) return dp[i][j][flag];
        int ans = 0;
        for(int k = i+1;k<j;k+=2)
        {
            int lt = f(str,i,k-1,true);
            int lf = f(str,i,k-1,false);
            int rt = f(str,k+1,j,true);
            int rf = f(str,k+1,j,false);
            
            if(str[k] == '&')
            {
                if(flag == true)
                {
                    ans = (ans + (lt * rt)%mod)%mod ;
                }
                else
                {
                    ans = (ans + (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
                }
            }
            else if(str[k] == '|')
            {
                if(flag == true) ans = (ans + (lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else ans = ans + (lf*rf)%mod;
            }
            else if(str[k] == '^')
            {
                if(flag == true) ans = (ans + (lt*rf)%mod + (lf*rt)%mod)%mod;
                else ans = (ans + (lt*rt)%mod + (rf*lf)%mod)%mod;
            }
        }
        return dp[i][j][flag] =  ans;
    }
    int countWays(int N, string S){
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<N+1;j++)
            {
                for(int k=0;k<2;k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        return f(S,0,N-1,true);
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