class Solution {
public:
    int solveReccursive(vector<int>&nums, int target,int start){
        //base case
        if(start ==nums.size())
            return target==0?1:0;
        int plus = solveReccursive(nums,target+nums[start],start+1);
        int minus = solveReccursive(nums,target-nums[start],start+1);
        return plus +minus; 
    }
     int solveMemo(vector<int>&nums, int target,int start, map<pair<int,int>,int>&dp){
        //base case
        if(start ==nums.size())
            return target==0?1:0;
         if(dp.find({start,target}) != dp.end() ) return dp[{start,target}];

        int plus = solveMemo(nums,target+nums[start],start+1,dp);
        int minus = solveMemo(nums,target-nums[start],start+1,dp);
        return dp[{start,target}] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int> ,int>dp;
        int ans = solveMemo(nums,target,0,dp);
        return ans;
    }
};