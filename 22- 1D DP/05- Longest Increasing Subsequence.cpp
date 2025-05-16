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


/// ------------------------------------------------------------------
// Another Solution 

class Solution {
public:
    int dp[2500+1];
    int solve(int i ,vector<int>& nums) {
        if (i == nums.size())
            return 0;

        int &res = dp[i];
        if (~res)
            return res ;

        res = 1 ; 
        for (int j = i + 1 ; j < nums.size() ; j++)
            if (nums[j] > nums[i])
                res = max(res , 1 + solve(j , nums));

        return res ;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp , -1 , sizeof dp);
        int maxLen = 0 ;
        for (int i = 0 ; i < nums.size() ; i++)
            maxLen = max(maxLen , solve(i , nums));
        return maxLen;
    }
};
