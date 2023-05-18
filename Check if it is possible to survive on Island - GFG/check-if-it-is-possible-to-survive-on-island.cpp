//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int s, int n, int m){
        int sun = s/7;
        int rem = s - sun;
        int tot = s*m;
        int ans = 0;
        if(tot%n==0)
        {
            ans = tot/n;
        }
        else
        {
            ans = tot/n + 1;
        }
        if(ans <= rem)
        {
            return ans;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends