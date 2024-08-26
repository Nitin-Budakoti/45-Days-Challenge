class Solution {
public:
    int solveReccursive(vector<int>&nums, int s , int e ,vector<vector<int>>&dp){
    //base case 1
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int ans = INT_MIN;
        for(int i =s;i<=e;++i){
            ans = max(ans , nums[s-1]*nums[i]*nums[e+1]+solveReccursive(nums,s,i-1,dp)+solveReccursive(nums,i+1,e,dp));
        }
       return dp[s][e] = ans;
        
    }
    int solveTab(vector<int>&nums,int n){
      vector<vector<int>>dp(n+2,vector<int>(n+2,0));  
        
        for(int s =n;s>=1;s--){
            for(int e = 1 ;e<=n;e++){
                if(s>e) continue;
                int ans = INT_MIN;
                    for(int i =s;i<=e;++i){
                       int cost = nums[s-1]*nums[i] *nums[e+1]+ dp[s][i-1] + dp[i+1][e];
                        ans = max(ans,cost);
                        
                    }
                       dp[s][e] = ans;
            }
        }
        return dp[1][n];
    }
    int maxCoins(vector<int>& nums) {
        int n =nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        
        
        int ans = solveTab(nums,n);
        return ans;
    }
};