Problem Link - https://leetcode.com/problems/3sum-closest/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        int mindiff = INT_MAX;
        sort(nums.begin(),nums.end());
        int ans;
        for(int i = 0;i<nums.size()-2;i++){
            int j = i+1,k = nums.size()-1;
            int newt = target - nums[i];

            while(j<k){
                if(nums[j] + nums[k] == newt)
                      return target;
               else if(nums[j] + nums[k] < newt){

                  if(mindiff >  (newt - (nums[j]+nums[k])) )
                  {
                      ans = nums[i] + nums[j] + nums[k];
                    mindiff = (newt - (nums[j]+nums[k]));
                  }
                   j++;
               }
                else{

                  if(mindiff >  ( (nums[j]+nums[k]) - newt) )
                  {
                      ans = nums[i] + nums[j] + nums[k];
                    mindiff = ( (nums[j]+nums[k]) - newt);
                  }
                   k--;
               }
            }
        }
        return ans;
    }
};
