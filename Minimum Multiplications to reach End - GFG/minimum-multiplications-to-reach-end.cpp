//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, INT_MAX);
        queue<pair<int,int>> q;
        q.push({start,0});
        dist[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            if(node == end)
            {
                return distance;
            }
            
            for(auto it: arr)
            {
                int mulnode = (it*node)%(100000);
                if(dist[mulnode] > distance + 1)
                {
                    dist[mulnode] = distance + 1;
                    q.push({mulnode,dist[mulnode]});
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