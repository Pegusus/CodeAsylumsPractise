Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int  i =0;i<nums.size();i++)
            mp[nums[i]]++;
        int n = mp.size();
        int* ans = new int[n];
        int i = 0;
        for(auto x : mp){
            ans[i] = x.first;
            i++;
        }
        nums.clear();
        for(int i= 0;i<n;i++)
            nums.push_back(ans[i]);
        return n;
    }
};
