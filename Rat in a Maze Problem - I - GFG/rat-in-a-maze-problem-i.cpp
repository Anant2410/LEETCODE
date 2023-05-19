//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>>& m, vector<string>&ans, string path, int row, int col, 
    vector<vector<int>>& vis, int n, int dr[], int dc[])
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(path);
            return;
        }
        string dir = "ULDR";
        for(int i=0;i<4;i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr>=0 && nr <n && nc>=0 && nc <n && !vis[nr][nc] && m[nr][nc])
            {
                vis[row][col] =1;
                solve(m,ans,path+dir[i],nr,nc,vis,n,dr,dc);
                vis[row][col] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,-1,0,+1};
        if(m[0][0] == 1)
            solve(m,ans,"",0,0,vis,n,dr,dc);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends