#include <lt_help/lt.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, lastPrice = prices[0];
        for(int price :  prices)
        {   if( price > lastPrice )
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
// 2023-03-10: Runtime 4ms 84.98% Memory 13MB 92.91%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/912724807/

