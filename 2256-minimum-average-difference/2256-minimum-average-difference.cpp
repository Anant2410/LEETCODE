class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int idx = 0;
        int ans = INT_MAX;
        long tot=0,curr=0;
        int n = nums.size();
        for(auto it: nums)
            tot += it;
        
        for(int i=0;i<nums.size();i++)
        {
            curr += nums[i];
            int avg1 = curr / (i+1);
            
            if(i==n-1)
            {
                if(avg1 < ans)
                    return n-1;
                else
                    break;
            }
            int avg2 = (tot-curr)/(n-i-1);
            
            if(abs(avg1-avg2) < ans)
            {
                ans = abs(avg1 - avg2);
                idx = i;
            }
        }
        return idx;
    }
};