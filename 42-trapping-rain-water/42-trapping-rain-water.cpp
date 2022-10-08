class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, maxl=0,maxr=0,low=0,high=height.size()-1;
        while(low<=high)
        {
            if(height[low] <= height[high])
            {
                if(height[low] > maxl)
                {
                    maxl = height[low];
                }
                else
                {
                    ans += maxl - height[low];
                }
                low++;
            }
            else if(height[high] < height[low])
            {
                if(height[high] > maxr)
                {
                    maxr = height[high];
                }
                else
                {
                    ans += maxr - height[high];
                }
                high--;
            }
        }
        return ans;
    }
};