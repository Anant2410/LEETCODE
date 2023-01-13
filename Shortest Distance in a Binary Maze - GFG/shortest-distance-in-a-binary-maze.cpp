//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        q.push({0,source});
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int adjdist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(x == destination.first && y == destination.second)
            {
                return adjdist;
            }
            for(int i=0;i<4;i++)
            {
                int newx = x + delrow[i];
                int newy = y + delcol[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy])
                {
                    if(dist[newx][newy] > 1 + adjdist)
                    {
                        dist[newx][newy] = 1 + adjdist;
                        q.push({dist[newx][newy],{newx,newy}});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends