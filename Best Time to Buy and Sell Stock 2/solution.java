class Solution {
    public int maxProfit(int[] prices) {
        int total = 0;
        int j = 1;
        for(int i = 0; j < prices.length; i++) {
            if(prices[j] > prices[i]) {
                total += (prices[j] - prices[i]);
            }
            j++;
        }
        
        return total;
    }
}