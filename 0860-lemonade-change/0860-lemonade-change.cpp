class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto it: bills)
        {
            if(it==5)
            {
                five++;
            }
            else if(it==10)
            {
                if(five==0)
                    return false;
                else
                {
                    ten++;
                    five--;
                }
            }
            else 
            {
                if(five==0 || (ten==0 && five<3))
                    return false;
                else if(ten>0)
                {
                    ten--;
                    five--;
                }
                else
                {
                    five-=3;
                }
            }
        }
        return true;
    }
};