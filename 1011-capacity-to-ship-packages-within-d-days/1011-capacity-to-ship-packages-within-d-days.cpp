class Solution {
public:
    bool f(vector<int>& weights, int days, int weight)
    {
        int day=1, curr=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i] > weight) return false;
            if(weights[i] + curr > weight)
            {
                day++;
                curr = weights[i];
            }
            else
            {
                curr += weights[i];
            }
        }
        if(day > days) return false;
        
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        if(days> weights.size()) return -1;
        int sum=0,mini=INT_MAX;
        int ans = -1;
        for(auto it: weights)
        {
            mini = min(mini, it);
            sum += it;
        }
        int low = mini, high = sum;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(f(weights,days,mid))
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