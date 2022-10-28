class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),sz=0;
        int ans = 0;
        while(j<n)
        {
            if(nums[j] == 0)
            {
                sz++;
            }
            if(sz <= k)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else if(sz > k)
            {
                while(sz>k)
                {
                    if(nums[i] == 0)
                    {
                        sz--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};