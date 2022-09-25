class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        bool flag = true;
        
        while(i<n && s[i] ==' ') i++;
        
        if(s[i] =='+')i++;
        else if(s[i] =='-')
        {
            flag=false;
            i++;
        }
        long ans = 0;
        while(i<n)
        {
            if(s[i] >= '0' && s[i] <='9')
            {
                ans = ans*10 + (s[i] - '0');
                if(ans >= INT_MAX) break;
            }
            else break;
            
            i++;
        }
        
        if(!flag) ans *= -1;
        
        if(ans <= INT_MIN) return INT_MIN;
        else if(ans >= INT_MAX) return INT_MAX;
        else
            return ans;
    }
};