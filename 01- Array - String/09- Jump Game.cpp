class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true ;
        int lastIdx = 0 ;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i > lastIdx)
                return false;
            lastIdx = max(lastIdx , i + nums[i]);
        }
        return lastIdx >= nums.size() - 1 ;
    }
};