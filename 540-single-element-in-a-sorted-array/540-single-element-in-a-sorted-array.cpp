class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            int idx = (mid%2==0) ? mid+1 : mid-1;
            
            if(nums[mid] == nums[idx]) low = mid+1;
            else high = mid;
        }
        return nums[low];
    }
};