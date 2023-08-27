//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	   // int dp[1001][1001];
	   // int lcs(string s, string t, int n, int m)
	   // {
	   //     if(n==0 || m==0) return 0;
	   //     if(dp[n][m] != -1) return dp[n][m];
	   //     if(s[n-1] == t[m-1] && n-1 != m-1)
	   //     {
	   //         return dp[n][m] = 1+ lcs(s,t,n-1,m-1);
	   //     }
	   //     return dp[n][m] =  max(lcs(s,t,n-1,m), lcs(s,t,n,m-1));
	   // }
	    int lcstab(string s, string t, int n, int m)
	    {
	        int dp[n+1][m+1];
	        for(int i=0;i<=n;i++)
	        {
	            dp[i][0] = 0;
	        }
	        for(int j=1;j<=m;j++)
	        {
	            dp[0][j] = 0;
	        }
	        for(int i=1;i<=n;i++)
	        {
	            for(int j=1;j<=m;j++)
	            {
	                if(s[i-1] == t[j-1] && i != j)
	                {
	                    dp[i][j] = 1 + dp[i-1][j-1];
	                }
	                else
	                {
	                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	                }
	            }
	        }
	        return dp[n][m];
	    }
		int LongestRepeatingSubsequence(string str){
		    string t = str;
		    //memset(dp, -1, sizeof(dp));
		    return lcstab(str,t,str.size(),t.size());
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends