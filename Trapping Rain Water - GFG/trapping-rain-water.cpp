//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long maxl=0,maxr=0;
        int low = 0, high = n-1;
        long long ans = 0;
        while(low<high)
        {
            if(arr[low] < arr[high])
            {
                if(arr[low] > maxl)
                {
                    maxl = arr[low];
                }
                else
                {
                    ans += maxl - arr[low];
                }
                low++;
            }
            else
            {
                if(arr[high] > maxr)
                {
                    maxr = arr[high];
                }
                else
                {
                    ans += maxr - arr[high];
                }
                high--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends