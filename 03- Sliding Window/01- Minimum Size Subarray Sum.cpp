class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int l = 0 , r = 0 ;
            int ans = 1e9 ;
            int sums = 0 ;
            while (r < nums.size()) {
                sums += nums[r] ;
    
                while (l <= r && sums >= target) {
                    ans = min(ans ,  r - l + 1);
                    sums -= nums[l] ;
                    l++ ;
                }
                    
                r++ ;
            }
            if (ans == 1e9)
                return 0 ; 
            return ans ;
        }
    };