//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&tar, vector<int>&res, int N){
	    int dr[8] = {2,2,-2,-2,1,1,-1,-1};
	    int dc[8] = {-1,1,1,-1,2,-2,2,-2};
	    
	    queue<pair<pair<int,int>,int>> q;
	    q.push({{tar[0],tar[1]},0});
	    vector<vector<int>>vis(N+1, vector<int>(N+1, 0));
	    vis[tar[0]][tar[1]] = 1;
	    int dist = INT_MAX;
	    
	    while(!q.empty())
	    {
	        auto it = q.front();
	        q.pop();
	        int r = it.first.first;
	        int c = it.first.second;
	        int t = it.second;
	        if(r == res[0] && c==res[1])
	        {
	            dist = min(dist,t);
	        }
	        for(int i=0;i<8;i++)
	        {
	            int nr = r + dr[i];
	            int nc = c + dc[i];
	            if(nr>0 && nr<=N && nc>0 && nc<=N && !vis[nr][nc])
	            {
	                vis[nr][nc] = 1;
	                q.push({{nr,nc},t+1});
	            }
	        }
	    }
	    return dist==INT_MAX ? -1  : dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends