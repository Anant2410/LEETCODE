//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        while(st.size() >= 2)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            // agar a knows b -> a is not celebrity (because celebrity does not know anyone)
            if(arr[a][b] == 1)
            {
                st.push(b);
            }
            //agar a did not know b -> b is not celebrity (because celebrity is known by all)
            else
            {
                st.push(a);
            }
        }
        int init = st.top();
        for(int i=0;i<n;i++)
        {
            if(i != init)
            {
                //agar koi person aesa jo celebrity ko nahi janta aur celebrity person ko jaanta hai to 
                // not possible
                if(arr[i][init] == 0 || arr[init][i] == 1)
                {
                    return -1;
                }
            }
        }
        return init;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends