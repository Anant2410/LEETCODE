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
        int prev = 0,prev2 = -1;
        for(int i=1;i<n;i++)
        {
            int up = prev + abs(height[i] - height[i-1]);
            int down = INT_MAX;
            if(i>1)
            {
                down = prev2 + abs(height[i] - height[i-2]);
            }
            int curr = min(up,down);
            
            prev2 = prev;
            prev = curr;
        }
        return prev;
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