Problem Link - https://leetcode.com/problems/valid-parentheses/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        while(i<s.length()){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else{
                if(st.empty())return false;

                switch(s[i]){
                    case ')': if(st.top()!='(')
                                return false;
                                else st.pop();
                                break;
                    case '}': if(st.top()!='{')
                                return false;
                                else st.pop();
                                break;
                    case ']': if(st.top()!='[')
                                return false;
                                else st.pop();
                                break;
                }
            }
            i++;
        }
        if(!st.empty())return false;
        return true;
    }
};
