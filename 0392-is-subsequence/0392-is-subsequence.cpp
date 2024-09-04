class Solution {
public:
    bool isSubsequence(string s, string t) {
        //trying brute force
//         bool is_found = false;
//         if(s.length()>t.length()) return false;
//         int k = 0 ,n=s.length(),m=t.length();
//         for(int i= 0 ;i<n; i++){
//             for(int j =k ; j<m;j++){
//             if(s[i] ==t[j]) 
//             {
//                 k = j+1;
//                 is_found=true;
//             }
//             }     
        
//         if(!is_found) return false;
//         is_found = false;
//     }
//         return true;
        
        //trying 2 pointer approach
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
            i++;
                j++;
            }
            else{
                j++;
            }
        }
        return  i == s.length();
  }
    
};