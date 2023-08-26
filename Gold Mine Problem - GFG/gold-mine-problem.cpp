//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[51][51];
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ud = matrix[i][j] + solve(matrix,i-1,j-1,n,m);
        int lr = matrix[i][j] + solve(matrix,i,j-1,n,m);
        int ld = matrix[i][j] + solve(matrix,i+1,j-1,n,m);
        
        return dp[i][j] = max({ud,lr,ld});
    }
    int maxGold(int n, int m, vector<vector<int>> matrix)
    {
        int ans = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            ans = max(ans, solve(matrix,i,m-1,n, m));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends