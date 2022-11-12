class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        int n = arr.size();
        while(low <=high)
        {
            int mid = low + (high-low)/2;
            
            if(mid>0 && mid<n-1)
            {
                if(arr[mid]>arr[mid-1] && arr[mid] > arr[mid+1])
                    return mid;
                else if(arr[mid] < arr[mid+1])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else if(mid==0)
            {
                if(arr[mid]>arr[mid+1])
                    return 0;
                else
                    return 1;
            }
            else if(mid==n-1)
            {
                if(arr[mid]>arr[mid-1])
                    return n-1;
                else
                    return n-2;
            }
        }
        return -1;
    }
};