//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>& arr, vector<int>& ans, int n, int sum, int idx)
    {
        if(idx == n)
        {
            ans.push_back(sum);
            return ;
        }
        solve(arr,ans,n,sum+arr[idx],idx+1);
        solve(arr,ans,n,sum,idx+1);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        solve(arr,ans,n,0,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends