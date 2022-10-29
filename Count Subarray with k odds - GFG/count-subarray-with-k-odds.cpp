//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int n, vector<int>& nums, int k)
    {
        int i=0,j=0,sum=0,count=0;
        while(j<n)
        {
            sum += nums[j];
            while(sum > k)
            {
                sum -= nums[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }
        return f(n,nums,k) - f(n,nums,k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends