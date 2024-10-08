class Solution {
public:
    int solveReccursive(vector<int>&arr , int i ){
      //base condition 
        if(i>=arr.size()) return 0;
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1 ;X<=3;X++){
            if(X+i-1>=arr.size()) break;
             total +=arr[X+i-1];
            ans = max(ans , total - solveReccursive(arr,i+X));
        }
        return ans;
    }
    
     int solveMemo(vector<int>&arr , int i,vector<int>&dp ){
      //base condition 
        if(i>=arr.size()) return 0;
         if(dp[i]!=-1) return dp[i];
        int ans = INT_MIN;
        int total = 0;
        for(int X = 1 ;X<=3;X++){
            if(X+i-1>=arr.size()) break;
             total +=arr[X+i-1];
            ans = max(ans , total - solveMemo(arr,i+X,dp));
        }
    dp[i] = ans;
         return ans;
    }
    
    int solveTab(vector<int>arr){
        vector<int>dp(arr.size()+1,0);
        int n =arr.size();
       
        for(int i = n-1; i>=0;--i){
             int ans = INT_MIN;
             int total = 0;
            for(int X = 1 ;X<=3;X++){
                if(X+i-1>=arr.size()) break;
                 total +=arr[X+i-1];
                 ans = max(ans , total - dp[i+X]);
        }
           dp[i] = ans;
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // vector<int>dp(stoneValue.size()+1,-1);
       int ans = solveTab(stoneValue);
        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
    }
};