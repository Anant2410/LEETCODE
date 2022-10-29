class Solution {
public:
    int f(vector<int>& nums, int k)
    {
        int i=0,j=0,sum=0,count=0;
        
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }
        return f(nums,k) - f(nums,k-1);
    }
};