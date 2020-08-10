Problem Link - https://leetcode.com/problems/merge-intervals/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int> > st;
        vector<vector<int> > ans;
        for(int i = 0;i<intervals.size();i++){
            if(st.empty())
                st.push(intervals[i]);
            else{
                vector<int> v = st.top();

                if(intervals[i][0] <= v[1]){
                    v[1] = max(v[1],intervals[i][1]);//if the interval completely lies within
                    st.pop();
                    st.push(v);
                }
                else{
                    ans.push_back(v);
                    st.pop();
                    st.push(intervals[i]);
                }
            }
        }
            if(!st.empty())
                ans.push_back(st.top());
            //st.pop();

        return ans;
    }
};
