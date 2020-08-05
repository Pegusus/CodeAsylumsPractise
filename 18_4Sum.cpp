Problem Link - https://leetcode.com/problems/4sum/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int> > v;
        set<vector<int> > sv;

        for(int i = 0;i<nums.size()-3;i++){
            int target1 = target - nums[i];


            for(int j = i+1;j<nums.size()-2;j++){
                int newt = target1 - nums[j];

                int k = j+1,l=nums.size()-1;

                while(k<l){
                    if(nums[k] + nums[l] == newt)
                        {
                        sv.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        }
                    if(nums[k] + nums[l] > newt)
                        l--;
                    if(nums[k] + nums[l] < newt)
                        k++;

                }
            }
        }
        for(auto x : sv)
            v.push_back(x);

        return v;
    }
};
