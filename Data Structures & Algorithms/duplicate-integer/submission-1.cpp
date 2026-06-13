class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mpp;
        for(int num : nums){
            if(mpp.find(num) != mpp.end()) return true;

            mpp.insert(num);
        }
        return false;
    }
};