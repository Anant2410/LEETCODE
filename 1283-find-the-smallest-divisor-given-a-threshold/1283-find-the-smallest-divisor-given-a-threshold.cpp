class Solution {
public:
    int f(vector<int>& nums, int mid)
    {
        int sum = 0;
        for(auto it: nums)
        {
            if(it%mid==0)
            {
                sum += it/mid;
            }
            else
            {
                sum += it/mid+1;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1,high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(f(nums,mid)> threshold)
            {
                low = mid+1;
            }
            else
            {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};