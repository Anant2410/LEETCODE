//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int knapSack(int n, int arr[], int sum)
    {
        if(n==0)
        {
            if(sum == 0)
            {
                return 1;
            }
            return 0;
        }
        if(sum == 0)
        {
            return 1;
        }
        if(dp[n][sum] != -1) return dp[n][sum];
        if(arr[n-1] <= sum)
        {
            int take = knapSack(n-1,arr,sum-arr[n-1]);
            int nottake = knapSack(n-1,arr,sum);
            
            return dp[n][sum] =  take || nottake;
        }
        return dp[n][sum] =  knapSack(n-1,arr,sum);
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        if(sum % 2)
        {
            return 0;
        }
        else
        {
            sum = sum/2;
            return knapSack(n,arr,sum); 
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends