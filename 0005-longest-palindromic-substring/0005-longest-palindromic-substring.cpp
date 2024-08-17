class Solution {
public:
    int start = 0;
    int max_len = 1;
    bool solve(string &s , int i , int j){
        if(i>=j) return true;
        bool flag = false;
        if(s[i]==s[j])
            flag = solve(s,i+1,j-1);
        if(flag){
            int curr_len = j-i+1;
            if(curr_len>max_len){
                max_len = curr_len;
                start = i;
            }
                                    
        }
        return flag;
    }
    string longestPalindrome(string s) {
        for(int i = 0 ;i<s.length();i++){
            for(int  j = i ; j<s.length();j++){
                bool t = solve(s,i,j);
            }
        }
        return s.substr(start ,max_len);
    }
};