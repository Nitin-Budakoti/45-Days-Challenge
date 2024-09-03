class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int l = 0;
        int n = s.length();
        for(int i = 0 ; i<n; i++){
        char ch = s[i];
            if(ch=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    l = max(l,i-st.top());
                }
            }
        }
        return l;
    }
};