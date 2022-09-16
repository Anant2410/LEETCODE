class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                long long rem = (long long)target - nums[i] - nums[j];
                int l = j+1,h=n-1;
                while(l<h)
                {
                    long long tar3 = nums[l] + nums[h];
                    if(tar3 > rem) h--;
                    
                    else if(tar3 < rem) l++;
                    
                    else
                    {
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[l];
                        temp[3] = nums[h];
                        ans.push_back(temp);
                        
                        while(l<h && nums[l] == temp[2]) l++;
                        while(l<h && nums[h] == temp[3]) h--;
                    }
                }
                while(j+1<n && nums[j+1] == nums[j]) j++;
            }
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};