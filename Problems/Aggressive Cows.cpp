class Solution {
  public:
    bool isPossible(vector<int> &arr, int k,int minDist)
    {
        int lastPos=arr[0],cows=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-lastPos>=minDist)
            {
                cows++;
                lastPos=arr[i];
            }
            if(cows==k)
            {
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) 
    {
        sort(arr.begin(),arr.end());
        int st=1;
        int n=arr.size();
        int end=arr[n-1]-arr[0];
        int ans=-1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(isPossible(arr,k,mid))
            {
                ans=mid;
                st=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};
