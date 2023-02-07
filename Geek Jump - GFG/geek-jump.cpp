//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   int f(int ind, vector<int>& arr, int n, vector<int>& dp)
//   {
//       if(ind==0) return 0;
//       if(dp[ind] != -1) return dp[ind];
//       int up = f(ind-1,arr,n,dp) + abs(arr[ind] - arr[ind-1]);
//       int down = INT_MAX;
//       if(ind>1)
//       {
//         down = f(ind-2,arr,n,dp) + abs(arr[ind] - arr[ind-2]);
//       }
      
//       return dp[ind] = min(up,down);
//   }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++)
        {
            int up = dp[i-1] + abs(height[i] - height[i-1]);
            int down = INT_MAX;
            if(i>1)
            {
                down = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(up,down);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends