class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[start] <= nums[mid]){
                if(target>= nums[start] && target<=nums[mid]){
                    end = mid;
                }
                else
                    start = mid+1;
            }
            else if(nums[mid] <= nums[end]){
                if(target>= nums[mid] && target<= nums[end])
                    start = mid+1;
                else
                    end = mid;
            }
        }
        return -1;
    }
};