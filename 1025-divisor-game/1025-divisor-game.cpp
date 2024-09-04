class Solution {
public:
    bool solveReccursive(int n ,bool alice ,bool bob){
        //base case
           if(n==1){
               if(bob) return true;
               return false;
           } 
        bool flag  = false;
        int i= 1;
        while(i<n){
         if(n%i==0){
            if(alice)
                flag = flag|| solveReccursive(n-i,0,1);
            else
                flag  = flag || solveReccursive(n-i,1,0);
         }
            i++;
        }
        return flag;
    }
    bool divisorGame(int n) {
       if (n % 2 == 0) {
            return true;
        }
        return false;
    }
};