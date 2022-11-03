class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>> maxi; // maxheap
        
        for(auto it: arr)
        {
            int temp = abs(it-x);
            maxi.push({temp,it});
            if(maxi.size() > k)
            {
                maxi.pop();
            }
        }
        while(!maxi.empty())
        {
            ans.push_back(maxi.top().second);
            maxi.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};