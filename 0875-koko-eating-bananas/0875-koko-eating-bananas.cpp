class Solution {
public:
    long f(vector<int>& piles, int k)
    {
        long sum = 0;
        for(int i=0;i<piles.size();i++)
        {
            sum += (piles[i]/k);
            if(piles[i]%k != 0)
            {
                sum += 1;
            }
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans=0;
        while(low<=high)
        {
            int k = (low+high)/2;
            
            if(f(piles,k) <= h)
            {
                ans = k;
                high = k-1;
            }
            else 
               low = k+1;
        }
        return ans;
    }
};