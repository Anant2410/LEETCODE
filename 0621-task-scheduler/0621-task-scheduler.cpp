class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int size = tasks.size();
        int max_freq = 0;
        for(auto it: tasks)
        {
            freq[it-65]++;
            max_freq = max(max_freq, freq[it-65]);
        }
        int result = (max_freq - 1) * (n+1);
        for(auto it: freq)
        {
            if(max_freq == it)
            {
                result ++;
            }
        }
        return max(result,size);
    }
};