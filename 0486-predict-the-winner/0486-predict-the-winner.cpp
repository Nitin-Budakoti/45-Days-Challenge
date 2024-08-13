class Solution {
public:
    int solveReccursive(vector<int>&nums,int s,  int e){
    //base case
    if(s==e) return nums[s];
       
    int bystart = nums[s] - solveReccursive(nums,s+1,e);
    int byend = nums[e]-solveReccursive(nums,s,e-1);
        
        return  max(bystart,byend);
    }
    int solveMemo(vector<int>&nums,int s,  int e, vector<vector<int>>&dp){
    //base case
    if(s==e) return nums[s];
         if(dp[s][e]!=-1) return dp[s][e];
    int bystart = nums[s] - solveMemo(nums,s+1,e,dp);
    int byend = nums[e]-solveMemo(nums,s,e-1,dp);
        return dp[s][e] = max(bystart,byend);
    }
    int solveTab(vector<int>&nums){
        vector<vector<int>>dp (nums.size(),vector<int>(nums.size()+1,-1));
        int i = nums.size();
        for(int i = 0 ; i<nums.size();i++) dp[i][i] =nums[i];
        
        
        for(int s = nums.size()-1;s>=0;--s){
            for(int e  = i; e<nums.size();e++){
                int bystart = nums[s] - dp[s+1][e];
                int byend = nums[e]-dp[s][e-1];
                dp[s][e] = max(bystart,byend);
            }
            --i;
        }
        return dp[0][nums.size()-1];
    }

    bool predictTheWinner(vector<int>& nums) {
        //ector<vector<int>>dp (nums.size(),vector<int>(nums.size(),-1));
        //int ans = solveMemo(nums ,0 ,nums.size()-1,dp);
        int ans = solveTab(nums);
        return ans>=0;
    }
};