//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fun(int price[],int n, int i, vector<vector<int>>& dp)
    {
        if(i==0) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        if(i<= n)
        {
            return dp[i][n] = max(price[i-1] + fun(price,n-i,i,dp), fun(price,n,i-1,dp));
        }
        return dp[i][n] = fun(price,n,i-1,dp);
    }
    int cutRod(int price[], int n) {
        int length[n];
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            length[i] = i+1;
        }
        return fun(price,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends