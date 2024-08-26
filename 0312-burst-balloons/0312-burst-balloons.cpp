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
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int ans = solveReccursive(nums,1,nums.size()-2 ,dp);
        return ans;
    }
};