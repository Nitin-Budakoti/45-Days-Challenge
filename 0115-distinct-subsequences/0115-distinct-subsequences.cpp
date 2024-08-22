class Solution {
public:
    int solveReccursive(string s , string t, int i,int j){
        //base case
        if(j==t.length()) return 1;
        if(i ==s.length() ) return 0;
        
        int ans = 0;
        if(s[i]==t[j])
            ans +=solveReccursive(s,t,i+1,j+1);
        ans+=solveReccursive(s,t,i+1,j);
        return ans;
        
         
        
    }
    
    
     int solveMemo(string &s , string &t, int i,int j,vector<vector<int>>&dp){
        //base case
        if(j==t.length()) return 1;
        if(i ==s.length() ) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        if(s[i]==t[j])
            ans +=solveMemo(s,t,i+1,j+1,dp);
        ans+=solveMemo(s,t,i+1,j,dp);
        return dp[i][j] = ans;
        
         
        
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size(),-1));
        int ans = solveMemo(s,t ,0,0,dp);
        return ans;
    }
};