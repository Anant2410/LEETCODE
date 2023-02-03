//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        queue<pair<int,int>> q;
        q.push({start,0});
        while(!q.empty())
        {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            if(node == end) return distance;
            for(auto it: arr)
            {
                int adjnode = (it*node)%100000;
                if(dist[adjnode] > distance + 1)
                {
                    dist[adjnode] = distance+1;
                    q.push({adjnode,dist[adjnode]});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends