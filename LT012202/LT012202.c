#include <lt_help/lt.h>

int maxProfit(int* prices, int pricesSize) {
    
    if( pricesSize < 2 || prices == NULL )
        return 0;
    
    int total = 0;
    int d, i;
    
    for( i = 1; i < pricesSize; ++i )
    {
        d = prices[i]-prices[i-1];
        if( d > 0 )
            total += d;
    }
    
    return total;
}


void test(int* prices, int pricesSize)
{
    printf("input: ");
    outputArray(prices, pricesSize);
    int r = maxProfit(prices, pricesSize);
    printf("; output: %d\n;", r);
}

int main(void)
{
    int prices[6] = {7,1,5,3,6,4};
    test(prices, 6);
}

// Result 
//
// 2022-11-21: Runtime 7ms 46.90% Memory 7MB 22.38%, https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/847466414/
