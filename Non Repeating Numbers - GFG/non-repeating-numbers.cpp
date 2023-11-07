//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int xorr = 0;
        for(int i=0;i<n;i++)
        {
            xorr = xorr ^ nums[i];
        }
        int cnt = 0;
        while(xorr)
        {
            if(xorr & 1)
            {
                break;
            }
            cnt++;
            xorr = xorr >> 1;
        }
        int xor1=0,xor2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] & (1<<cnt))
            {
                xor1 = xor1 ^ nums[i];
            }
            else
            {
                xor2 = xor2 ^ nums[i];
            }
        }
        if(xor1 > xor2)
        {
            return {xor2,xor1};
        }
        return {xor1,xor2};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends