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
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = solveReccursive(nums,target,0);
        return ans;
    }
};