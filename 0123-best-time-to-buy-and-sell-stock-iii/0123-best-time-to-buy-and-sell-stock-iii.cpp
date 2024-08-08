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
    
    int maxProfit(vector<int>& prices) {
        //int ans = solveReccursive(prices,0,true,2);
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        
        int ans = solveMemo(prices,0,true,2,dp);
        return ans;
        
    }
};