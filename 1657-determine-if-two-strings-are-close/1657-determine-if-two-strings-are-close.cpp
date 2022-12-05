class Solution {
public:
    bool closeStrings(string word1, string word2) {
       vector<int>arr(26,0),arr2(26,0);
        set<char> s1,s2;
        for(auto it: word1)
        {
            arr[it-'a']++;
            s1.insert(it);
        }
        for(auto it: word2)
        {
            arr2[it-'a']++;
            s2.insert(it);
        }
        sort(arr.begin(), arr.end());
        sort(arr2.begin(), arr2.end());
        
        return arr==arr2 && s1==s2;
    }
};