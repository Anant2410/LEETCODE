class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto it: arr)
        {
            int num = abs(x-it);
            pq.push({num,it});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty())
        {
            int num = pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};