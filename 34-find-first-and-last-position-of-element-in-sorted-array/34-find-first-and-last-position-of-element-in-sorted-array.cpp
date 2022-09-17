class Solution {
public:
    int firstOccurance(vector<int>& nums, int target)
    {
        int l = 0, h = nums.size()-1;
        int res =-1;
        
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(nums[m]  == target)
            {
                res = m;
                h = m-1;
            }
            else if(nums[m] > target) h = m-1;
            else l = m+1;
        }
        return res;
    }
    int lastOccurance(vector<int>& nums, int target)
    {
        int l = 0, h = nums.size()-1;
        int res =-1;
        
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(nums[m]  == target)
            {
                res = m;
                l = m+1;
            }
            else if(nums[m] > target) h = m-1;
            else l = m+1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int x = firstOccurance(nums,target);
        int y = lastOccurance(nums,target);
        
        ans.push_back(x);
        ans.push_back(y);
        
        return ans;
    }
};