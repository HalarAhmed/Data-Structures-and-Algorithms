class Solution {
  public:
    bool isValid(vector<int>& arr, int k,int minMinutes)
    {
        int painters=1;int n=arr.size();int minutes=0;
        for(int i=0;i<n;i++)
        {
            if(minutes+arr[i]<=minMinutes)
            {
                minutes+=arr[i];
            }
            else
            {
                painters++;
                minutes=arr[i];
            }
        }
        return painters>k? false:true;
    }
    int minTime(vector<int>& arr, int k) 
    {
        int end=0;int n=arr.size();int ans=-1;int maxVal=INT_MIN;
        for(int i=0;i<n;i++)
        {
            end+=arr[i];
            maxVal=max(maxVal,arr[i]);
        }
        int st=maxVal;
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
