class Solution {
public:
    int MIN_CAL(int st , int end , vector<int>& nums){
      int MIN_NUM = INT_MAX;
      for(;st<=end;st++){
        MIN_NUM = min(nums[st] , MIN_NUM);
      }
      return MIN_NUM;
    }
    int MAX_CAL(int st , int end , vector<int>& nums){
       int MAX_NUM = INT_MIN;
      for(;st<=end;st++){
        MAX_NUM = max(nums[st] , MAX_NUM);
      }
      return MAX_NUM;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n  = nums.size()-1;
        vector<int> ANS;
        for(int i=0;i<=n;i++){
           long long MIN_FROM_LAST = MIN_CAL(i,n,nums);
           long long MAX_FROM_START = MAX_CAL(0,i,nums);
           long long int DIFF =  MAX_FROM_START - MIN_FROM_LAST;
           if(DIFF<=k)return i;
        }
        
       
     return -1;
    }
};
