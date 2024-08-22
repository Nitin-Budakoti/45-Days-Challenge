class Solution {
public:
    int solveReccursive(vector<int>&arr, int i ,int t){
        if(i == arr.size()) return 0;
        int include = 0;
        include = arr[i]*t + solveReccursive(arr,i+1,t+1);
        int exclude = solveReccursive(arr,i+1,t);
        return max(include,exclude);
    }
    int solveMemo(vector<int>&arr, int i ,int t,vector<vector<int>>&dp){
        if(i == arr.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int include = 0;
        include = arr[i]*t + solveMemo(arr,i+1,t+1,dp);
        int exclude = solveMemo(arr,i+1,t,dp);
        return dp[i][t] =max(include,exclude);
    }
    int solveTab(vector<int>&arr){
        vector<vector<int>>dp(arr.size()+2 ,vector<int>(arr.size()+2,0));
        for(int i = arr.size()-1;i>=0 ;--i){
            for(int t = arr.size();t>=0;--t){
                 int include = arr[i]*t + dp[i+1][t+1];
                 int exclude = dp[i+1][t];
                     dp[i][t] =max(include,exclude);
            }
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() ,satisfaction.end());
        vector<vector<int>>dp(satisfaction.size()+1 ,vector<int>(satisfaction.size()+1,-1));
        int ans = solveTab(satisfaction);
        return ans;
    }
};