//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long largestRectangleArea(vector<long long>& heights) {
        long long n = heights.size();
        vector<long long> leftsmaller(n),rightsmaller(n);
        stack<long long> st;

        //find the leftsmaller of every index
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                leftsmaller[i] = -1;
            }
            else if(!st.empty() && heights[st.top()] < heights[i])
            {
                leftsmaller[i] = st.top();
            }
            else
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    leftsmaller[i] = -1;
                }
                else
                {
                    leftsmaller[i] = st.top();
                }
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        //find rightheight of the index
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                rightsmaller[i] = n;
            }
            else if(!st.empty() && heights[st.top()] < heights[i])
            {
                rightsmaller[i] = st.top();
            }
            else
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    rightsmaller[i] = n;
                }
                else
                {
                    rightsmaller[i] = st.top();
                }
            }
            st.push(i);
        }
        long long  ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,(rightsmaller[i] - leftsmaller[i] - 1)*heights[i]);
        }
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(arr[i]);
        }
        return largestRectangleArea(v);
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends