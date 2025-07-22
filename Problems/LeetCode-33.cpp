class Solution {
public:
    int search(vector<int>& nums, int tar) 
    {
        int st=0; 
        int end=nums.size()-1;int mid;
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(nums[mid]==tar)
            {
                return mid;
            }
            if(nums[st]<=nums[mid])    // left sorted
            {
                if(tar>=nums[st] && tar<=nums[mid])
                {
                    end=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }
            else    // right sorted
            {
                if(tar>=nums[mid] && tar<=nums[end])
                {
                    st=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
