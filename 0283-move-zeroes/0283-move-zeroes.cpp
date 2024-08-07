class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros =0;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]==0) zeros++;
    }
        vector<int>arr;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]!=0)
                arr.push_back(nums[i]);
        }
      for(int i = 0; i<arr.size();i++){
          nums[i]=arr[i];
        }  
      for(int i = arr.size(); i<nums.size();i++){
          nums[i]=0;
        }
        
    }
};