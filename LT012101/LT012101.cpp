#include <lt_help/lt.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = -1, min_price = INT_MAX;
        for(int price : prices )
        {   min_price  = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);
        }
        return max_profit;
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
// 2022-11-21: Runtime 271ms 12.69% Memory 93.3MB 56.24%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/847462655/
// 2023-02-22: Runtime 150ms 39.20% Memory 93.4MB 11.86%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/902639546/
// 2023-03-10: Runtime 117ms 96.23% Memory 93.2MB 91.61%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/912722650/


