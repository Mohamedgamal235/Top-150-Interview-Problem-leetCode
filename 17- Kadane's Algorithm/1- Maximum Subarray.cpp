class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int prefix_sum = 0 ;
            int mini_prefix = INT_MAX ;
            int maxi_prefix = INT_MIN ;
    
            for (int i = 0 ; i < nums.size() ; i++) {
                prefix_sum += nums[i] ;
                maxi_prefix = max(maxi_prefix , prefix_sum);
    
                if (i)
                    maxi_prefix = max(maxi_prefix , prefix_sum - mini_prefix);
    
                mini_prefix = min(mini_prefix , prefix_sum);
            }
    
            return maxi_prefix ; 
        }
    };