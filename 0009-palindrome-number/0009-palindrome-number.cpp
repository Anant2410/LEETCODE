class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x;
        long long ans = 0;
        if(x<0) return false;
         while(x!=0){
             int rem = x %10;
             ans = ans*10 + rem;
             x /=10;
         }
        if(ans==temp) return true;
        
        return false;
    }
};