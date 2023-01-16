//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Disjoint{
    vector<int> parent, size;
public:
    Disjoint(int n)
    {
        
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    int find_parent(int node)
    {
        if(node == parent[node]) return node;
        
        return parent[node] = find_parent(parent[node]);
    }
    void us(int u, int v)
    {
        int paru = find_parent(u);
        int parv = find_parent(v);
        if(size[paru] < size[parv])
        {
            parent[paru] = parv;
            size[parv] += size[paru];
        }
        else
        {
            parent[parv] = paru;
            size[paru] += size[parv];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                int node= i;
                int adjnode = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,adjnode}});
            }
        }
        Disjoint ds(V);
        int ans = 0;
        sort(edges.begin(), edges.end());
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.find_parent(u) != ds.find_parent(v))
            {
                ans += wt;
                ds.us(u,v);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends