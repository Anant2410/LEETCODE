//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> ways(n,0), dist(n,1e9);
        dist[0] = 0;
        ways[0] = 1;
        //{dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int wt = it.second;
                if(dist[adjnode] > distance + wt)
                {
                    dist[adjnode] = distance + wt;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(dist[adjnode] == distance + wt)
                {
                    ways[adjnode] += ways[node];
                }
            }
        }
        return ways[n-1]%(1000000007);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends