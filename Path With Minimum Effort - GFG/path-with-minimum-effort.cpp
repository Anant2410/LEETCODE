//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        //time complexity is e log v
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c== m-1) return diff;
            for(int i=0;i<4;i++)
            {
                int newr = r + delrow[i];
                int newc = c + delcol[i];
                if(newr >=0 && newr <n && newc >=0 && newc < m)
                {
                    int neweffort = max(abs(heights[r][c] - heights[newr][newc]) , diff);
                    if(dist[newr][newc] > neweffort)
                    {
                        dist[newr][newc] = neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends