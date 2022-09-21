class Solution {
public:
    bool f(vector<int>&nums,int target, int m)
    {
        int x = 1, sum = 0;
        for(auto it: nums)
        {
            if(it>target) return false;
            if(it+sum > target)
            {
                x++;
                sum = it;
            }
            else
            {
                sum += it;
            }
        }
        if(x>m) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int mini=INT_MAX;
        int sum = 0;
        for(auto it: nums)
        {
            mini = min(mini,it);
            sum += it;
        }
        int low=mini,high=sum;
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(f(nums,mid,m))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};