class Solution {
public:
    int solveReccursive(vector<int>& nums1, vector<int>& nums2,int i , int p1 , int p2 ){
        //base case 
        if(i==nums2.size()) return 0;
        int swap = INT_MAX, no_swap=INT_MAX;
        //swaping case
        if(p1<nums2[i] && p2<nums1[i])
            swap = 1+ solveReccursive(nums1,nums2,i+1,nums2[i],nums1[i]);
        if(p1<nums1[i] && p2<nums2[i])
            no_swap = solveReccursive(nums1,nums2 ,i+1,nums1[i],nums2[i]);
        return min(swap,no_swap);
    }
    
    
    int solveMemo(vector<int>& nums1, vector<int>& nums2,int i , int p1 , int p2,vector<vector<int>>&dp ,int is_swap){
        //base case 
        if(i==nums2.size()) return 0;
        if(dp[i][is_swap]!=-1) return dp[i][is_swap];
        int swap = INT_MAX, no_swap=INT_MAX;
        //swaping case
        if(p1<nums2[i] && p2<nums1[i])
            swap = 1+ solveMemo(nums1,nums2,i+1,nums2[i],nums1[i],dp ,1);
        if(p1<nums1[i] && p2<nums2[i])
            no_swap = solveMemo(nums1,nums2 ,i+1,nums1[i],nums2[i],dp,0);
         dp[i][is_swap]=min(swap,no_swap);
        return dp[i][is_swap];
    }
    
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
        int n = nums1.size();
        for(int i = n-1; i>=1 ;--i){
            for(int is_swap = 1; is_swap>=0;--is_swap){
                
                int p1 = nums1[i-1];
                int p2 = nums2[i-1];
                if(is_swap){
                     swap(p1,p2);
                }
                int swap = INT_MAX;
                int no_swap=INT_MAX;
                if(p1<nums2[i] && p2<nums1[i])
                    swap = 1+dp[i+1][1];
                if(p1<nums1[i] && p2<nums2[i])
                    no_swap = dp[i+1][0];
                dp[i][is_swap]=min(swap,no_swap);     
            }
        }
        return dp[1][0];
    }
    
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //int ans= solveReccursive(nums1,nums2,0,-1,-1);
        int n = nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int ans = solveTab(nums1, nums2);
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int ans= solveMemo(nums1,nums2,0,-1,-1,dp,0);
        return ans;
    }   
};