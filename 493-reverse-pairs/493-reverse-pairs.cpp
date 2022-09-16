class Solution {
public:
    int merge(vector<int>& nums, int l, int m, int h)
    {
        int i = l, j = m+1;
        int res = 0;
        while(i<=m && j<=h)
        {
            long long temp = nums[j];
            if(nums[i] > 2* temp)
            {
                res += m-i+1;
                j++;
            }
            else i++;
        }
        sort(nums.begin()+l, nums.begin()+h+1);
        return res;
    }
    int ms(vector<int>& nums, int l , int h)
    {
        if(l>=h) return 0;
            int m = (l+h)/2;
            int cnt = ms(nums,l,m);
            cnt+= ms(nums,m+1,h);
            cnt += merge(nums,l,m,h);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return ms(nums,0,n-1);
    }
};