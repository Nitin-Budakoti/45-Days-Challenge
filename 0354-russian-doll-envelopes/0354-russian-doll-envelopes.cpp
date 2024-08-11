class Solution {
public:
    // static bool cmp(vector<int>&a , vector<int>&b){
    //     if(a[0]==b[0]) return a[1]<b[1];
    //     return a[0]<b[0];
    // }
    int solveReccursive(vector<vector<int>>&arr,int curr, int prev){
        //base case
    if(curr>=arr.size()) return 0;
        
        //include exclude pattern 
    int include = 0;
        if(prev==-1 || (arr[curr][0]> arr[prev][0]  && arr[curr][1]> arr[prev][1])){
            include = 1 + solveReccursive(arr,curr+1,curr);    
        }
        int exclude = solveReccursive(arr,curr+1,prev);
        
        return max(include,exclude);    
    }
    
    int solveMemo(vector<vector<int>>&arr,int curr, int prev,vector<vector<int>>&dp){
        //base case
    if(curr>=arr.size()) return 0;
        //dp checking 
        if(dp[prev+1][curr]!=-1) return dp[curr][prev+1]; 
        //include exclude pattern 
    int include = 0;
        if(prev==-1 || (arr[curr][0]> arr[prev][0]  && arr[curr][1]> arr[prev][1])){
            include = 1 + solveMemo(arr,curr+1,curr,dp);    
        }
        int exclude = solveMemo(arr,curr+1,prev,dp);
        dp[prev+1][curr] = max(include,exclude);
        return  dp[prev+1][curr];
    }
    //main solution using with binary search
    static bool cmp(vector<int>&a , vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    int solveBS(vector<vector<int>>&arr){
    //sort the array width increasing order and when width are equal then sort decreasing order
        sort(arr.begin(),arr.end(),cmp);
        if(arr.size()==0) return 0;
        vector<int>anser;
        anser.push_back(arr[0][1]);
        for(int i = 1 ; i<arr.size();++i){
            if(arr[i][1]>anser.back()) anser.push_back(arr[i][1]);
            else{
                int index = lower_bound(anser.begin(),anser.end(),arr[i][1])-anser.begin();
                anser[index] = arr[i][1];
            }
        }
        return anser.size();
    }
    
 
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort(envelopes.begin(),envelopes.end());
        //vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        int ans = solveBS(envelopes);
        return ans;
    }
};