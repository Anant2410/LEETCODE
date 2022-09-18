class Solution {
public:
    int searchInsert(vector<int>& nums, int k) {
         int l = 0, h = nums.size()-1;
        while(l<=h)
        {
            int m = l + (h-l)/2;
            
            if(nums[m]  == k) return m;
            
            else if(nums[m] > k) h = m-1;
             
            else l = m+1;
        }
        return l;
    }
};