//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
// 	int subsetSum(int arr[], int sum, int n)
// 	{
// 	    if(n==0)
//         {
//             return arr[0] == sum;
//         }
//         if(sum==0)
//         {
//             return 1;
//         }
        
//         if(arr[n-1] <= sum)
//         {
//             return perfectSum(arr,n-1,sum-arr[n-1]) + perfectSum(arr,n-1,sum);
//         }
//         return perfectSum(arr,n-1,sum);
// 	}
	int perfectSum(int arr[], int n, int sum)
	{
        long long m=1e9+7;
        int dp[n+1][sum+1];
        
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]]%m+dp[i-1][j]%m;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]%m;
                }
            }
            
        }
        return dp[n][sum]%m;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends