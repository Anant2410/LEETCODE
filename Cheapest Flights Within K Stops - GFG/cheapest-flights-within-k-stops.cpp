//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>> adj[n];
        for(auto it: flights)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int distance = q.front().second.second;
            q.pop();
            if(stops > K) continue;
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int wt = it.second;
                if(dist[adjnode] > wt + distance && stops <=K)
                {
                    dist[adjnode] = wt + distance;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends