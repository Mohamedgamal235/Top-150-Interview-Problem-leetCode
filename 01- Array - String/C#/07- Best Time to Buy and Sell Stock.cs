public class Solution {
    public int MaxProfit(int[] prices) {
        int buy = prices[0] ;
            int profit = 0 ;
    
            for (int i = 1 ; i < prices.Length ; i++) {
                profit = Math.Max(profit , prices[i] - buy);
                buy = Math.Min(buy , prices[i]);
            }
            return profit ;
    }
}