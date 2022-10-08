class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--)
        {
           if(st.empty())
           {
               mp[nums2[i]] = -1;
           }
            else if(!st.empty() && st.top() > nums2[i])
            {
                mp[nums2[i]] = st.top();
            }
            else
            {
                while(!st.empty() && st.top() < nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                    mp[nums2[i]] = -1;
                else
                    mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(auto it: nums1)
        {
            ans.push_back(mp[it]);
        }
        return ans;
    }
};