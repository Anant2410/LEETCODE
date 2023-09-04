//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int entry[], int exit[], int n)
	{
	   sort(entry, entry+n);
	   sort(exit, exit+n);
	   
	   int guest_in=1, guest_max = 1, time = entry[0];
	   int i=1,j=0;
	   
	   while(i<n && j<n)
	   {
	       if(entry[i] <= exit[j])
	       {
	           guest_in++;
	           
	           if(guest_in > guest_max)
	           {
	               guest_max = guest_in;
	               time = entry[i];
	           }
	           i++;
	       }
	       else
	       {
	           guest_in--;
	           j++;
	       }
	   }
	   return {guest_max, time};
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends