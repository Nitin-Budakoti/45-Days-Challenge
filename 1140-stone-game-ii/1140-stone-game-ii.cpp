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
    
    int solveTab(vector<int>&piles){
    vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-0)));
        int n = piles.size();
        for(int i = n-1 ; i>=0 ; --i){
            for(int M = 1 ; M < piles.size();++M ) {
                for(int alice = 0 ;alice<2 ;alice++){
                    int ans =alice? INT_MIN:INT_MAX;
                      int total = 0;
                      for(int X = 1 ;X<=2*M;X++){
                         if((i+X-1)>= piles.size()) break;
                            total += piles[i+X-1];
                         if(alice){
                            ans = max(ans,total +dp[i+X][max(X,M)][0]);
                          }
                         else{
                                ans = min(ans , dp[i+X][max(X,M)][1]);          
                          }
                        dp[i][M][alice] = ans;
                    }
                    
                }            
            }
                                     
           }
            return dp[0][1][1];
        }                             
    int stoneGameII(vector<int>& piles) {
        //int ans = solveReccursive(piles,0,1,true);
       // vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        //int ans = solveMemo(piles,0,1,true,dp);
        if(piles.size()==1) return piles[0];
        int ans  =  solveTab(piles);
        return ans;
        
    }
};