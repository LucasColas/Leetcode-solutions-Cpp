class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int begin=0;
        int end=nums.size();
        int mid;
        if(target>nums[end-1]){
            return end;
        }
        while(begin<=end){
              mid=(begin+end)/2;
            if(nums[mid]==target){
                return mid;
            }
          
            if(target<nums[mid]){     
            end=mid-1;    
            }else{
            begin=mid+1;        
            }
          
        }
        return  begin;
    }
};
