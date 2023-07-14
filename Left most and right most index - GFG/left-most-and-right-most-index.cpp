//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long  fun(vector<long long> v, long long x)
    {
        long long low = 0, high = v.size()-1;
        long  ans = -1;
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            if(v[mid] == x)
            {
                ans = mid;
                high = mid-1;
            }
            else if(v[mid] > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
    long  fun2(vector<long long> v, long long x)
    {
        long long low = 0, high = v.size()-1;
        long  ans = -1;
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            if(v[mid] == x)
            {
                ans = mid;
                low = mid+1;
            }
            else if(v[mid] > x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long  first = fun(v,x);
        long  last = fun2(v,x);
        pair<long,long>p;
        p.first = first;
        p.second = last;
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends