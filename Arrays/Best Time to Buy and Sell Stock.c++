class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lowest = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > lowest)
            {
                profit = max(prices[i] - lowest, profit);
            }
            lowest = min(lowest, prices[i]);
        }
        return profit;
    }
};