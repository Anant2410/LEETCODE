//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
    {  
        int dp[n];
        int i, j;
        for(i=0;i<n;i++)
        {
            dp[i]=arr[i];
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    if(dp[i]< (arr[i]+dp[j]))
                    {
                        dp[i]=arr[i]+dp[j];
                    }
                }
            }
        }
        int max=INT_MIN;
        for(i=0;i<n;i++)
        {
            if(dp[i]>max)
            {
                max=dp[i];
            }
        }
        return max;
    }  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends