//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int f(int day, int last, vector<vector<int>>& colors, vector<vector<int>>& dp)
    {
        if(day==0) 
        {
            int maxi = INT_MAX;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    maxi = min(maxi, colors[0][i]);
                }
            }
            return dp[day][last] =  maxi;
        }
        int maxi=INT_MAX;
        for(int j=0;j<3;j++)
        {
            if(j!= last)
            {
                int ans = colors[day][j] + f(day-1,j,colors,dp);
                maxi = min(maxi,ans);
            }
        }
        return dp[day][last] =  maxi;
    }
    int minCost(vector<vector<int>> &colors, int n) {
        vector<vector<int>> dp(n, vector<int>(4,0));
        dp[0][0] = min(colors[0][1] , colors[0][2]);
        dp[0][1] = min(colors[0][0] , colors[0][2]);
        dp[0][2] = min(colors[0][1] , colors[0][0]);
        dp[0][3] = min(colors[0][1] , min(colors[0][0],colors[0][2]));

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = INT_MAX;
                for (int task = 0; task <= 2; task++) {
                    if (task != last) {
                        int activity = colors[day][task] + dp[day - 1][task];
                        dp[day][last] = min(dp[day][last], activity);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends