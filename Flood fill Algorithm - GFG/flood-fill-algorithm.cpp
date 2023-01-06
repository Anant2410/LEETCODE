//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int sr, int sc, int color, vector<vector<int>>&ans, vector<vector<int>>&image, int initial_color)
    {
        ans[sr][sc] = color;
        if(sr+1 < image.size() && image[sr+1][sc] == initial_color && ans[sr+1][sc] != color)
        {
            dfs(sr+1,sc,color,ans,image,initial_color);
        }
        if(sr-1>=0 && image[sr-1][sc] == initial_color && ans[sr-1][sc] != color)
        {
            dfs(sr-1,sc,color,ans,image,initial_color);
        }
        if(sc+1<image[0].size() && image[sr][sc+1] == initial_color && ans[sr][sc+1] != color)
        {
            dfs(sr,sc+1,color,ans,image,initial_color);
        }
        if(sc-1>=0 && image[sr][sc-1] == initial_color && ans[sr][sc-1] != color)
        {
            dfs(sr,sc-1,color,ans,image,initial_color);
        }
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initial_color = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc,newColor,ans,image,initial_color);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends