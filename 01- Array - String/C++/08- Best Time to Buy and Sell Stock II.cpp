class Solution {
public:
    int dp[30005][2] ;
    // 0 -> not holding
    // 1 -> holding
    int solve(int i , bool holding , vector<int>& prices) {
        if (i == prices.size())
            return 0;

        int &res = dp[i][holding];
        if (~res)
            return res ;

        int skip = solve(i + 1 , holding , prices); // option 1
        int op2 ; // option 2
        if (!holding)
            op2 = solve(i + 1 , true , prices) - prices[i];
        else
            op2 = solve(i + 1, false , prices) + prices[i];

        return res = max(skip , op2);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof dp);
        return solve(0,false, prices);
    }
};