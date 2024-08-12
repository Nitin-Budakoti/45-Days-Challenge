class Solution {
public:
    int solve(int n )
    {
     //base case
        if(n==0) return 1;
        if(n<0) return 0;
        int s = sqrt(n);
        int ans = INT_MAX;
        for(int i = 1; i<=s;i++)
        {
            int ps = i*i;
            ans =  min(ans ,1+ solve(n-ps));
        }
        return ans;
    }
    int solvememo(int n ,  vector<int>&dp)
    {
     //base case
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int s = sqrt(n);
        int ans = INT_MAX;
        for(int i = 1; i<=s;i++)
        {
            int ps = i*i;
            ans =  min(ans ,1+ solvememo(n-ps,dp));
        }
        dp[n] =ans;
        return ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1 ,-1);
        int ans = solvememo(n ,dp);
        return ans-1;
    }
};