//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        //for declaring the smaller part array first
        if(arr2.size() < arr1.size()) return MedianOfArrays(arr2,arr1);
        
        int n1 = arr1.size();
        int n2 = arr2.size();
        //setting high and low for the first  array
        int low = 0, high = n1;
        //apply binary search
        while(low<=high)
        {
            //find cut1  i.e middle
            int cut1 = low + (high-low)/2;
            //cut2 is  the remaining left half
            int cut2 = (n1+n2+1)/2 - cut1;
            //if zero or max set to INT_MIN or INT_MAX
            int l1=cut1==0 ?INT_MIN : arr1[cut1-1];
            int l2=cut2==0 ?INT_MIN : arr2[cut2-1];
            
            int r1=cut1==n1 ?INT_MAX : arr1[cut1];
            int r2=cut2==n2 ?INT_MAX : arr2[cut2];
            
            //if all the condition met
            if(l1<=r2 && l2 <= r1)
            {
                //if even 
                if((n1+n2)%2==0)
                {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                // if  odd
                else
                {
                    return max(l1,l2);
                }
            }
            //move left
            else if(l1 > r2)
            {
                high = cut1-1;
            }
            //move right
            else
            {
                low = cut1+1;
            }
        }
        return 0.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends