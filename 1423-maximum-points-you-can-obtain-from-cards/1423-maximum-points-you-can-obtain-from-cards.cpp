class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total_pts = 0;
        for(auto it: cardPoints)
        {
            total_pts += it;
        }
        if(n==k)
        {
            return total_pts;
        }
        int size = n-k;
        int sum=0,i=0,j=0;
        int ans = INT_MIN;
        while(j<n)
        {
            sum += cardPoints[j];
            if(j-i+1 < size)
            {
                j++;
            }
            else if(j-i+1 == size)
            {
                ans = max(ans, total_pts - sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};