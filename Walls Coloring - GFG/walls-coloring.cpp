//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    int minCost(vector<vector<int>> &colors, int n) {
        vector<int> prev(4,0);
        prev[0] = min(colors[0][1] , colors[0][2]);
        prev[1] = min(colors[0][0] , colors[0][2]);
        prev[2] = min(colors[0][1] , colors[0][0]);
        prev[3] = min(colors[0][1] , min(colors[0][0],colors[0][2]));

        for (int day = 1; day < n; day++) {
            vector<int> curr(4,0);
            for (int last = 0; last < 4; last++) {
                curr[last] = INT_MAX;
                for (int col = 0; col <= 2; col++) {
                    if (col != last) {
                        int work = colors[day][col] + prev[col];
                        curr[last] = min(curr[last], work);
                    }
                }
            }
            prev = curr;
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
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends