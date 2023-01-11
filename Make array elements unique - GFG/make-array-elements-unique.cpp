//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
       sort(arr.begin(), arr.end());
       int count = 0;
       for(int i=0;i<N;i++)
       {
           for(int j=i+1;j<N;j++)
           {
               if(arr[i] == arr[j])
               {
                   arr[j] = arr[j] + 1;
                   count++;
               }
               else
               {
                   break;
               }
           }
       }
       return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends