class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int length = 0;
        int gap = 0;
        int i=0;
        int j = height.size()-1;
        
        while(i<j){
            gap = j-i;
            length = min(height[i], height[j]);
            if(length==height[i]){
                    i++;
                }
            else{
                j--;
            }
            area = max(area, length*gap);
        }
        return area;
    }
};