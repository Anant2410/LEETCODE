//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
   int solve(vector<int>& arr, int n) {
        if(n==0) return 0;
        int sum = 0;
        int ans = INT_MIN;
        for(auto it: arr)
        {
            sum += it;
            ans = max(ans, sum);
            if(sum <0)
            {
                sum = 0;
            }
        }
        return ans;
    }
	int maxSubstring(string s)
	{
	    int n = s.size();
	    vector<int> arr(n);
	    for(int i=0;i<n;i++)
	    {
	        if(s[i] == '0')
	        {
	            arr[i] = 1;
	        }
	        else
	        {
	            arr[i] = -1;
	        }
	    }
	    return solve(arr,n);
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends