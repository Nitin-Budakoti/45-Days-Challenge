class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     //brute forse solution
        // for(int i = 0 ; i<nums.size()-1;i++)
        // {
        //     for(int j = i+1 ; j<nums.size();j++){
        //         if(nums[i]==nums[j]) return nums[j];
        //     }
        // }
        // return -1;
        // tortoise algorith method 
        int fast = nums[0];
        int slow = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};