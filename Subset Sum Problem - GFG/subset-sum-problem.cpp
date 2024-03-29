//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool solve(vector<int>& arr ,int sum, int n, vector<vector<int>>& dp)
    // {
    //     if(n==0)
    //     {
    //         return arr[0] == sum;
    //     }
    //     if(sum == 0)
    //     {
    //         return true;
    //     }
    //     if(dp[n][sum] != -1) return dp[n][sum];
    //     if(arr[n-1] <= sum)
    //     {
    //         return dp[n][sum] = solve(arr,sum-arr[n-1],n-1,dp) || solve(arr,sum,n-1,dp);
    //     }
    //     else if(arr[n-1] > sum)
    //     {
    //         return dp[n][sum] = solve(arr,sum,n-1,dp);
    //     }
    // }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;
        }
        for(int j=1;j<=sum;j++)
        {
            dp[0][j] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends