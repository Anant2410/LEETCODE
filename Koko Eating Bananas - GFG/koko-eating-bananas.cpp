//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long f(vector<int>& piles, int k)
    {
        long sum = 0;
        for(int i=0;i<piles.size();i++)
        {
            sum += (piles[i]/k);
            if(piles[i]%k != 0)
            {
               sum += 1;
            }
        }
        return sum;
    }
    int Solve(int N, vector<int>& piles, int H) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans=0;
        while(low<=high)
        {
            int k = (low+high)/2;
            
            if(f(piles,k) <= H)
            {
                ans = k;
                high = k-1;
            }
            else 
               low = k+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends