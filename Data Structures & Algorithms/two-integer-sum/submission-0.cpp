class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i< nums.size() ; i++){
            int value = target - nums[i];
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] == value){
                    return {i , j};
                }
            }
        }
        return {};
    }
};
