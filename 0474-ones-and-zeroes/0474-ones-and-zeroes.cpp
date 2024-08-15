class Solution {
public:
    void convert(vector<pair<int,int>>&arr, vector<string>&strs){
        for(auto x: strs){
            int zeros = 0, ones=0;
            for(auto ch : x){
                if(ch=='0') ++zeros;
                else     ++ones;
            }
            arr.push_back({zeros,ones});
        }
    }
    int solveReccursive(vector<pair<int,int>>&arr,int i ,int m , int n){
        if(i==arr.size()) return 0;
        
        int zeros = arr[i].first;
        int ones  = arr[i].second;
        int include = 0 ,exclude = 0;
        if(m-zeros>=0 && n-ones>=0)
            include = 1 + solveReccursive(arr,i+1,m-zeros,n-ones);
        exclude = solveReccursive(arr,i+1,m,n);
        return max(include,exclude);
    }
    int solveMemo(vector<pair<int,int>>&arr,int i ,int m , int n, vector<vector<vector<int>>>&dp){
        if(i==arr.size()) return 0;
        if(dp[i][m][n] !=-1) return dp[i][m][n];
        int zeros = arr[i].first;
        int ones  = arr[i].second;
        int include = 0 ,exclude = 0;
        if(m-zeros>=0 && n-ones>=0)
            include = 1 + solveMemo(arr,i+1,m-zeros,n-ones,dp);
        exclude = solveMemo(arr,i+1,m,n,dp);
        return dp[i][m][n]= max(include,exclude);
    }
    
    int solveTab(vector<pair<int,int>>&arr, int x , int y){
         vector<vector<vector<int>>>dp(arr.size()+1,vector<vector<int>>(x+1 ,vector<int>(y+1,0)));
         int n = arr.size();
         for(int i = n-1; i>=0;--i){
             for(int m = 0 ; m<=x;m++){
                 for(int n = 0 ; n<=y;n++){
                     int zeros = arr[i].first;
                     int ones  = arr[i].second;
                     int include = 0 ,exclude = 0;
                     if(m-zeros>=0 && n-ones>=0)
                        include = 1 + dp[i+1][m-zeros][n-ones];
                     exclude = dp[i+1][m][n];
                     dp[i][m][n]= max(include,exclude);
                 }
             }
         }
        return dp[0][x][y];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>arr;
        convert(arr,strs);
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1 ,vector<int>(n+1,-1)));
        int ans = solveTab(arr,m,n);
        return ans;
        
    }
};