class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        int r = 0, c = col-1;
        
        while(r>=0 && r<row && c>=0 && c<col)
        {
            //find all directions
            int up = r-1 < 0 ? -1 : mat[r-1][c];
            int down = r+1 >= row ? -1 : mat[r+1][c];
            int left = c-1 < 0 ? -1 : mat[r][c-1];
            int right = c+1 >= col ? -1: mat[r][c+1];
            
            if(mat[r][c] > up && mat[r][c] > down && mat[r][c] > left && mat[r][c] > right)
            {
                return {r, c};
            }
            
            int maxi = max({up,down,left,right});
            
            if(maxi==up) r--;
            else if(maxi==down) r++;
            else if(maxi==left) c--;
            else if(maxi==right) c++;
        }
        return {-1, -1};
    }
};