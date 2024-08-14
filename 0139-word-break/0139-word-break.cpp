class Solution {
public:
    bool check(string &word , vector<string>&dict){
    for(auto i :dict){
        if(i==word)
            return true;
    }
        return false;
    }
    bool solveReccursive(string s , vector<string>&dict,int start){
        //base case 
        if(start==s.length()) return true;
        string word ="";
        bool flag = false;
        for(int i = start ; i<s.length();i++){
            word+=s[i];
            if(check(word , dict)){
            flag = flag || solveReccursive(s,dict,i+1);
            }
        }
        return flag;
    }
     bool solveMemo(string &s , vector<string>&dict,int start, vector<int>&dp){
        //base case 
        if(start==s.length()) return true;
         if(dp[start]!=-1) return dp[start];
        string word ="";
        bool flag = false;
        for(int i = start ; i<s.length();i++){
            word+=s[i];
            if(check(word , dict)){
            flag = flag || solveMemo(s,dict,i+1,dp);
            }
        }
         dp[start] = flag;
        return flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length()+1,-1);
        return solveMemo(s,wordDict,0,dp);
        
    }
};