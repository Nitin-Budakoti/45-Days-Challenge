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
    int solveTab(vector<int>&nums, int &tar){
        map<pair<int,int> ,int>dp;
        dp[{nums.size() ,0}] =1;
        int sum =0;
        for(int i = 0 ; i<nums.size();i++) sum+=nums[i];
        for(int start = nums.size()-1;start>=0;start--){
            for(int target = -sum; target<=sum;target++){
                 int plus = dp.find({start+1,target+nums[start]})!=dp.end()? dp[{start+1,target+nums[start]}]:0;                 
                 int minus = dp.find({start+1,target-nums[start]})!=dp.end()? dp[{start+1,target-nums[start]}]:0;
                dp[{start,target}] = plus+minus;
            }
        }
        return dp[{0,tar}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //map<pair<int,int> ,int>dp;
        int ans = solveTab(nums,target);
        return ans;
    }
};