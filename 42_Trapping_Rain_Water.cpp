Problem Link - https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int* minHeightboth(vector<int> height){
        int n = height.size();

        int* minhl = new int[n];
        int* minhr = new int[n];

        minhl[0] = height[0];
        minhr[n-1] = height[n-1];

        for(int i = 1;i<n;i++)
            minhl[i] = max(minhl[i-1],height[i]);
        for(int i = n-2;i>=0;i--)
            minhr[i] = max(minhr[i+1],height[i]);

        int* mini = new int[n];
        for(int i = 0;i<n;i++)
            mini[i] = min(minhl[i],minhr[i]);

        return mini;
    }
    int trap(vector<int>& height) {
        if(height.size()==0)return 0;
        int* contribution = minHeightboth(height);
        int ans = 0;
        for(int i = 1;i<height.size()-1;i++){
            ans += (contribution[i] - height[i]);
        }
        return ans;
    }
};
