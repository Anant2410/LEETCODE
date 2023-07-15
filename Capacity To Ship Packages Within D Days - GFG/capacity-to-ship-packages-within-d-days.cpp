//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool possible(vector<int>& weights, int ship_wt, int total_days, int n)
    {
        int days = 1;
        int totwt = 0;

        for(auto it: weights)
        {
            if(it > ship_wt) return false;

            if(it + totwt > ship_wt)
            {
                days++;
                totwt = it;
            }
            else
            {
                totwt += it;
            }
        }

        if(days > total_days) return false;

        return true;
    }
    int leastWeightCapacity(int arr[], int N, int days) {
        // code here
        vector<int> weights;
        for(int i=0;i<N;i++)
        {
            weights.push_back(arr[i]);
        }
        int sum = 0;
        int mini = INT_MAX;
        int n = weights.size();
        int ans = -1;
        for(auto it: weights)
        {
            sum += it;
            mini = min(mini,it);
        }
        int low = mini, high = sum;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(possible(weights,mid,days,n))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends