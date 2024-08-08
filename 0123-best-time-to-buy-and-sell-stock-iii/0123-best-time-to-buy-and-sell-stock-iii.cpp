class Solution {
public:
    int solveReccursive(vector<int>&prices, int i ,bool buy,int limit){
        if(i>=prices.size() || limit==0) return 0;
        int profit  = 0;
        if(buy){
            int buy_profit = -prices[i]+ solveReccursive(prices ,i+1,false,limit);
            int skip = solveReccursive(prices, i+1,true,limit);
            profit = max(buy_profit,skip);
            }
        else{
            int sell_profit = prices[i]+solveReccursive(prices,i+1,true,--limit);
            int skip= solveReccursive(prices,i+1,false,limit);
            profit= max(sell_profit , skip);
        }
        return profit;
    }
    
    
     int solveMemo(vector<int>&prices, int i,bool buy,int limit, vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || limit==0) return 0;
         if(dp[i][buy][limit] !=-1) return dp[i][buy][limit];
        int profit  = 0;
        if(buy){
            int buy_profit = -prices[i]+ solveMemo(prices ,i+1,false,limit,dp);
            int skip = solveMemo(prices, i+1,true,limit,dp);
            profit = max(buy_profit,skip);
            }
        else{
            int sell_profit = prices[i]+solveMemo(prices,i+1,true,limit-1,dp);
            int skip= solveMemo(prices,i+1,false,limit,dp);
           profit= max(sell_profit ,skip);
        }
         dp[i][buy][limit] =profit;
        return profit;
    }
    int solveTab(vector<int>& prices){
         vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
         int n = prices.size();
        for(int i = n-1;i>=0;i--){
             int profit  = 0;
            for(int buy = 0 ;buy<2;buy++){
                for(int limit= 1 ; limit<3 ; limit++){
                     
                        if(buy){
                            int buy_profit = -prices[i]+ dp[i+1][0][limit];
                            int skip = dp[i+1][1][limit];
                            profit = max(buy_profit,skip);
                            }
                        else{
                            int sell_profit = prices[i]+dp[i+1][1][limit-1];
                            int skip= dp[i+1][0][limit];
                           profit= max(sell_profit ,skip);
                        }
                         dp[i][buy][limit] =profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int solveSO(vector<int>&prices){
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(3,0)));
        int n = prices.size();
        for(int i = n-1;i>=0;i--){
             int profit  = 0;
            for(int buy = 0 ;buy<2;buy++){
                for(int limit= 1 ; limit<3 ; limit++){
                     
                        if(buy){
                            int buy_profit = -prices[i]+ dp[1][0][limit];
                            int skip = dp[1][1][limit];
                            profit = max(buy_profit,skip);
                            }
                        else{
                            int sell_profit = prices[i]+dp[1][1][limit-1];
                            int skip= dp[1][0][limit];
                           profit= max(sell_profit ,skip);
                        }
                         dp[0][buy][limit] =profit;
                }
                 
            }
           dp[1]= dp[0];
        }
        return dp[0][1][2];
    }
    
    int maxProfit(vector<int>& prices) {
        //int ans = solveReccursive(prices,0,true,2);
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        
        //int ans = solveTab(prices);
        int ans = solveSO(prices);
        return ans;
        
    }
};