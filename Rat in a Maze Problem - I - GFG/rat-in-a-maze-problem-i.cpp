//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>>& m, vector<string>&ans, string path, int row, int col, 
    vector<vector<int>>& vis, int n)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(path);
            return;
        }
        //for down
        if(row+1<n && !vis[row+1][col] && m[row+1][col])
        {
            vis[row][col] = 1;
            solve(m,ans,path+'D',row+1,col,vis,n);
            vis[row][col] = 0;
        }
        //up
        if(row-1>=0 && !vis[row-1][col] && m[row-1][col])
        {
            vis[row][col] = 1;
            solve(m,ans,path+'U',row-1,col,vis,n);
            vis[row][col] = 0;
        }
        //right
        if(col+1 < n && !vis[row][col+1] && m[row][col+1])
        {
            vis[row][col] = 1;
            solve(m,ans,path+'R',row,col+1,vis,n);
            vis[row][col] = 0;
        }
        //left
        if(col-1>=0 && !vis[row][col-1] && m[row][col-1])
        {
            vis[row][col] = 1;
            solve(m,ans,path + 'L', row,col-1,vis,n);
            vis[row][col] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        if(m[0][0] == 1)
            solve(m,ans,"",0,0,vis,n);
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