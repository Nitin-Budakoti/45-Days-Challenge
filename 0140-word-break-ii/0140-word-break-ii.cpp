class Solution {
public:
    vector<string> solveReccursive(string &s , unordered_map<string ,bool>&dict , int  j){
        if(j == s.size()) return {""};
        vector<string>ans;
        string word;
        for(int i = j; i<s.size();i++){
        word.push_back(s[i]);
         if(dict[word]==false) continue;
         
         auto right = solveReccursive(s ,dict ,i+1);
         for(auto r_part : right){
            string end ;
             if(r_part.size() > 0 )  end = " "+r_part;
             ans.push_back(word + end);
         }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word : wordDict) dict[word] = 1;
        return  solveReccursive(s ,dict,0);
    }
};