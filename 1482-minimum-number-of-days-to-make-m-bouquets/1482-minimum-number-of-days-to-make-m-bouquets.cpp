class Solution {
public:
   bool f(vector<int>& bloomDay, int m, int k, int mid)
    {
        int adj = 0, bouqet=0;
        for(auto it: bloomDay)
        {
            if(it>mid) adj = 0;
            
            else if(++adj >=k)
            {
                bouqet++;
                adj=0;
            }
        }
        if(bouqet >= m) return true;     
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = 1e9;
        int res = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(f(bloomDay,m,k,mid))
            {
                res = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
};