class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int target = nums.size() / 2 ; 
            map<int ,int> mp ;
            for (auto x : nums) 
                mp[x]++ ; 
    
            int ans = 0 ; 
            for (auto x : nums) {
                if (mp[x] > target) {
                    ans = x ;
                    break;
                }
            }
    
            return ans ; 
        }
    };