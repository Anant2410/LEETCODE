
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            long dist = (x*x + y*y);
            pq.push({dist,{x,y}});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            auto it = pq.top();
            vector<int> temp;
            temp.push_back(it.second.first);
            temp.push_back(it.second.second);
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};