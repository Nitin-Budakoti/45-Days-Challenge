class Solution {
public:
    int solveReccursive(int n){
    //base case 
        if(n==0) return 1;
        if(n<0) return 0;
        int end = sqrt(n);
        int ans= INT_MAX;
        for( int i = 1 ; i<=end;i++ ){
            int number = i*i;
            ans = min(ans ,1+ solveReccursive(n-number));
    }
        return ans;
    } 
    
    int solveMemo(int n ,vector<int>&dp){
     //base case 
        if(n==0) return 1;
        if(n<0) return 0;
        //check condition for dp
        if(dp[n]!=-1) return dp[n];
        int end = sqrt(n);
        int ans= INT_MAX;
        for( int i = 1 ; i<=end;i++ ){
            int number = i*i;
            ans = min(ans ,1+ solveMemo(n-number,dp));
    }
        dp[n]= ans;
        return ans;
    }
    
    int numSquares(int n) {
        //int ans = solveReccursive(n);
        vector<int>dp(n+1,-1);
        int ans = solveMemo(n,dp);
        return ans-1;
    }
};