//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fun(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp)
    {
        if(day==0)
        {
            int maxi = 0;
            for(int i=0;i<3;i++)
            {
                maxi = max(maxi,points[0][i]);
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int ans = 0;
        for(int task=0;task<3;task++)
        {
            if(last!=task)
            {
                int point = points[day][task] + fun(day-1,task,points,dp);
                ans = max(ans,point);
            }
        }
        return dp[day][last]  = ans;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int> prev(4,0);
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][1], points[0][0]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day = 1;day<n;day++)
        {
            vector<int> temp(4,0);
            for(int last = 0;last<4;last++)
            {
                int ans = 0;
                for(int task=0;task<3;task++)
                {
                    if(last!=task)
                    {
                        int point  = points[day][task] + prev[task];
                        ans = max(ans,point);
                    }
                }
                temp[last] = ans;
            }
            prev = temp;
        }
        return prev[3];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends