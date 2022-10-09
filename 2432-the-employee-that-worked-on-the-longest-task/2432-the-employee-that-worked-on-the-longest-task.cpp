class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int start =0, maxi = INT_MIN,id=0;
        for(int i=0;i<logs.size();i++)
        {
            int end = logs[i][1];
            int work = end-start;
            if(work > maxi)
            {
                maxi = work;
                id = logs[i][0];
            }
            else if(work == maxi)
            {
                id = min(id, logs[i][0]);
            }
            start = end;
        }
        return id;
    }
};