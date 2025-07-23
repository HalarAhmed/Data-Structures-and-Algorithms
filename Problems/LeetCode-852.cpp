class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int st=0;
        int end=arr.size()-1;
        int mid=st+(end-st)/2;;
        while(true)
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid]<arr[mid-1])
            {
                mid--;
            }
            else
            {
                mid++;
            }
        }
        return -1;
    }
};
