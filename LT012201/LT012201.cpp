#include <lt_help/lt.h>



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if( prices.empty() )
            return 0;
   
        int profit = 0;
        int lastPrice = prices[0];
        for( size_t i = 1; i < prices.size(); ++i )
        {
            int price = prices[i];
            if( price > lastPrice )
                profit += price - lastPrice;
            
            lastPrice = price;
        }
        
        return profit;
    }
};   
   
   
void test(vector<int> prices)
{
    cout << "input: ";
    outputVector(prices);
    int r = Solution().maxProfit(prices);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({7,1,5,3,6,4});
}

// Result 
//
// 2022-11-21: Runtime 0ms 100% Memory 12.9MB 92.62%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/847465082/

