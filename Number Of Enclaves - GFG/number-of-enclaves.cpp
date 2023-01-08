//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty())
        {
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newr = nr + delrow[i];
                int newc = nc + delcol[i];
                if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() 
                && !vis[newr][newc] && grid[newr][newc] ==1)
                {
                    q.push({newr,newc});
                    vis[newr][newc] = 1;
                }
            }
        }
        return;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1)
            {
                bfs(i,0,vis,grid);
            }
            if(grid[i][m-1] == 1)
            {
                bfs(i,m-1,vis,grid);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i] == 1)
            {
                bfs(0,i,vis,grid);
            }
            if(grid[n-1][i] == 1)
            {
                bfs(n-1,i,vis,grid);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] ==1)
                {
                    count++;
                }
            }
        }
        return count;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends