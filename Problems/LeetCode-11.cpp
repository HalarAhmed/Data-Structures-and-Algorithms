class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i=0;
        int j=height.size()-1;
        int area=0;
        int maxArea=0;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                area=height[i]*(j-i);
                maxArea=max(area,maxArea);
                i++;
            }
            else if(height[i]>height[j])
            {
                area=height[j]*(j-i);
                maxArea=max(area,maxArea);
                j--;
            }
            else if(height[i]==height[j])
            {
                area=height[i]*(j-i);
                i++;
                j--;
                maxArea=max(area,maxArea);
            }
        }
        return maxArea;
    }
};
