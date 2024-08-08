class Solution {
public:
    void getmaxprofit(vector<int>&prices,int i , int &min_price ,int& max_profit){
      //base case 
        if(i == prices.size()) return ;
        if(prices[i]<min_price) min_price = prices[i];
        int today = prices[i]-min_price;
        max_profit = max(max_profit , today);
        getmaxprofit(prices,i+1,min_price,max_profit);
    }
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = INT_MIN;
        getmaxprofit(prices,0,min_price, max_profit);
        return max_profit;
    }
};