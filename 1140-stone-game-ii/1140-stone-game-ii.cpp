class Solution {
public:
    int solveReccursive(vector<int>&piles,int i,int M,bool alice){
        //base case
        if(i == piles.size()) return 0;
        int ans =alice? INT_MIN:INT_MAX;
        int total = 0;
        for(int X = 1 ;X<=2*M;X++){
            if((i+X-1)>= piles.size()) break;
            total += piles[i+X-1];
            if(alice){
                ans = max(ans,total +solveReccursive(piles,i+X,max(X,M),!alice));
                }
            else{
                ans = min(ans , solveReccursive(piles,i+X, max(X,M),!alice));
                }
        }
        return ans ;
  }
    
    int solveMemo(vector<int>&piles,int i,int M,int alice, vector<vector<vector<int>>>&dp){
        //base case
        if(i == piles.size()) return 0;
        if(dp[i][M][alice] !=-1) return dp[i][M][alice];
        int ans =alice? INT_MIN:INT_MAX;
        int total = 0;
        for(int X = 1 ;X<=2*M;X++){
            if((i+X-1)>= piles.size()) break;
            total += piles[i+X-1];
            if(alice){
                ans = max(ans,total +solveMemo(piles,i+X,max(X,M),!alice,dp));
                }
            else{
                ans = min(ans , solveMemo(piles,i+X, max(X,M),!alice,dp));
                }
        }
        dp[i][M][alice] = ans;
        return ans;
  }
    int stoneGameII(vector<int>& piles) {
        //int ans = solveReccursive(piles,0,1,true);
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        int ans = solveMemo(piles,0,1,true,dp);
        return ans;
        
    }
};