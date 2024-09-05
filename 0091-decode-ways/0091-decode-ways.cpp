class Solution {
public:
    int n = 0;
    int solveReccursive(string s , int pos, vector<int>&dp){
        if(pos==n) return 1;
        if(dp[pos]!=-1) return dp[pos];
        if(s[pos]=='0') return 0;
         int count = solveReccursive(s ,pos+1,dp);
         if(pos<n-1 && s.substr(pos,2)<"27"){
            count += solveReccursive(s,pos+2,dp);   
         }
        return dp[pos]=count;
    }
    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(s.size(),-1);
        return solveReccursive(s,0,dp);
    }
};