class Solution {
public:
    int f(string s)
    {
        int ans = 0;
        for(auto it: s)
        {
            if(it == 'a' || it == 'e' || it == 'o' || it == 'u' ||
              it == 'A' || it == 'E' || it == 'O' || it == 'U' || it == 'i' || it == 'I')
                ans++;
        }
        return ans;
    }
    bool halvesAreAlike(string s) {
        string temp = "";
        string temp2 = "";
        for(int i=0;i<s.size()/2;i++)
        {
            temp += s[i];
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            temp2 += s[i];
        }
        int vow1 = f(temp);
        int vow2 = f(temp2);
        if(vow1==vow2)
            return true;
        return false;
    }
};