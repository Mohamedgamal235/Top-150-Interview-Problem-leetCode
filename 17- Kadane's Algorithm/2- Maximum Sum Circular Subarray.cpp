class Solution {
    public:
        int maxSubarray(vector<int>& nums) {
            int max_ending = -1e5;
            int max_so_far = -1e5 ;
            for (int i = 0 ; i < nums.size() ; i++) {
                max_ending = max(nums[i] , max_ending + nums[i]);
                max_so_far = max(max_so_far , max_ending);
            }
            return max_so_far ;
        }
        int minSubarray(vector<int>& nums) {
            int min_ending = 1e9 ;
            int min_so_far = 1e9 ;
            for (int i = 0 ; i < nums.size() ; i++) {
                min_ending = min(nums[i] , min_ending + nums[i]);
                min_so_far = min(min_so_far , min_ending);
            }
            return min_so_far;
        }
        int sums(vector<int>& nums) {
            int sum = 0 ;
            for (int i = 0 ; i < nums.size() ; i++)
                sum += nums[i] ;
            return sum ;
        }
    
        int maxSubarraySumCircular(vector<int>& nums) {
            int maxi = maxSubarray(nums);
            int mini = minSubarray(nums);
            int sum = sums(nums);
    
            if (sum == mini)
                return maxi ;
            return max(maxi , sum - mini);
        }
    };