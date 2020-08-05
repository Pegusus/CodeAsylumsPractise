Problem Link - https://leetcode.com/problems/3sum/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)return {};
        int target = 0;
        set<vector<int> > sv;
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        for(int  i = 0;i<nums.size()-2;i++){
            int newt = target - nums[i];

            int j = i+1,k = nums.size()-1;
            while(j<k){
                if(nums[j] + nums[k] > newt)
                    k--;
                if(nums[j] + nums[k] < newt)
                    j++;
                if(nums[j] + nums[k] == newt && j!=k)
                {
                    sv.insert({nums[i],nums[j],nums[k]});
                    // if(j!=nums.size()-1 && k!=0 && j<k)
                    j++;k--;

                }
            }
        }
        for(auto x : sv){
            ans.push_back(x);
        }
        return ans;
    }
};
