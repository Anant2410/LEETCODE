#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        st.push(0);
        left[0] = 1;
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i] = i+1;
            }
            else
            {
                left[i] = i-st.top();
            }
            
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        st.push(n-1);
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
          while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right[i] = n-i;
            }
            else
            {
                right[i] = st.top()-i;
            }
            
            st.push(i);  
        }
        for(int i=0;i<n;i++)
        {
            long long prod = (left[i] * right[i])%mod;
            prod = (prod*arr[i])%mod;
            sum = (sum+prod)%mod;
        }
        return sum;
    }
};