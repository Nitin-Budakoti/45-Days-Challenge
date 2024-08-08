class Solution {
public:
    int solveReccursive(vector<int>&prices, int i ,bool buy,int fee){
        if(i>=prices.size() ) return 0;
        int profit  = 0;
        if(buy){
            int buy_profit =  -prices[i]+ (solveReccursive(prices ,i+1,false,fee)-fee);
            int skip = solveReccursive(prices, i+1,true,fee);
            profit = max(buy_profit,skip);
            }
        else{
            int sell_profit = prices[i]+solveReccursive(prices,i+1,true,fee);
            int skip= solveReccursive(prices,i+1,false,fee);
            profit= max(sell_profit , skip);
        }
        return profit;
    }
     int solveMemo(vector<int>&prices,int i, bool buy,vector<vector<int>>&dp,int fee){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit =0;
        if(buy){
            int buy_profit = -prices[i]+(solveMemo(prices,i+1,false,dp,fee))-fee;
            int skip = solveMemo(prices,i+1,true,dp,fee);
            profit= max(buy_profit,skip);
        }
        else{
            int sell_profit = prices[i]+solveMemo(prices,i+1,true,dp,fee);
            int skip = solveMemo(prices,i+1,false,dp,fee);
             profit = max(sell_profit,skip);
        }
        dp[i][buy]= profit;
        return dp[i][buy];
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans = solveMemo(prices , 0 , true,dp,fee);
        return ans;
    }
};