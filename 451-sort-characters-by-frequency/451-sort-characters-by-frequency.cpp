class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans;
        for(auto it: s)
        {
            mp[it]++;
        }
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }
        while(!pq.empty())
        {
            auto it =  pq.top();
            pq.pop();
            if(it.first>0)
            {
                while(it.first>0)
                {
                    ans.push_back(it.second);
                    it.first--;
                }
            }
        }
        return ans;
    }
};