class Solution 
{
  public:
    bool isValid(vector<int> &arr, int k,int maxAllowedPages)
    {
        int n=arr.size();int pages=0;int students=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maxAllowedPages)
            {
                return false;
            }
            if(pages+arr[i]<=maxAllowedPages)
            {
                pages+=arr[i];
            }
            else
            {
                students++;
                pages=arr[i];
            }
        }
        return students>k?false:true;
    }
    int findPages(vector<int> &arr, int k) 
    {
        int st=0,end=0,ans=-1,n=arr.size();
        if(k>n)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            end+=arr[i];
        }
        int mid=st+(end-st)/2;
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(isValid(arr,k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return ans;
    }
};
