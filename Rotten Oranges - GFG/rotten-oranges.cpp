//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int t = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int tm = 0;
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty())
        {
            int nr = q.front().first.first;
            int nc = q.front().first.second;
            int tc = q.front().second;
            q.pop();
            tm = max(tm,tc);
            for(int i=0;i<4;i++)
            {
                int newr = nr+dr[i];
                int newc = nc+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] ==1 && vis[newr][newc] == 0)
                {
                    q.push({{newr,newc},tc+1});
                    vis[newr][newc] = 2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] ==1 && vis[i][j] !=2)
                {
                    return -1;
                }
            }
        }
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends