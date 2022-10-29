class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int i=0,j=0,sum=0,count=0;
        if(k<0) return 0;
        
        while(j<nums.size())
        {
            sum += nums[j];
            while(sum > k)
            {
                sum -= nums[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
    }
};