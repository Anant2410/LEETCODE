class Solution {
public:
    void f(int i, string digits, string ds, vector<string>& ans, string mp[])
    {
        if(i>=digits.size())
        {
            ans.push_back(ds);
            return;
        }
        int num = digits[i] - '0';
        string value = mp[num];
        for(int j=0;j<value.size();j++)
        {
            ds.push_back(value[j]);
            f(i+1,digits,ds,ans,mp);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
        {
            return ans;
        }
        string ds="";
        string mp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        f(0,digits,ds,ans,mp);
        return ans;
    }
};