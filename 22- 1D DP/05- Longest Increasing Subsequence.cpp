class Solution {
public:
    int dp[2500+1][2500+1] ;

    int solve(int i , int prev , vector<int>& nums) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        int op1 = solve(i + 1 , prev , nums );
        int op2 = {} ;
        if (prev >= nums.size() || nums[i] > nums[prev])
            op2 = solve(i + 1 , i , nums) + 1 ;

        return dp[i][prev] = max(op1 , op2);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp , -1 , sizeof dp);
        return solve(0 , nums.size(), nums);
    }
};