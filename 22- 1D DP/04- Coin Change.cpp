class Solution {
public:
    int dp[10005];
    int solve(int x , vector<int>& coins) {
        if (x < 0)
            return 1e9;
        if (x == 0)
            return 0;

        int &res = dp[x] ;
        if (~res)
            return res;

        res = 1e9  ;
        for (auto c : coins)
            res = min(res , solve(x - c , coins) + 1);

        return res ;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp , -1 , sizeof dp);
        int ans = solve(amount , coins);
        return ans >= 1e9 ? -1 : ans ;
    }
};