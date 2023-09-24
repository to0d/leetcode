#include <lt_help/lt.h>

class Solution {
public:
    // f(n, m) = f(n-1, m)                               when coins[n-1] > m
    //         = min( f(n-1, m), f(n, m-coins[n-1]) +1 ) when coins[n-1] <= m
    //         = 0                                       when m == 0
    //         = MAX                                     when n == 0
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<int> arr((size+1)*(amount+1), 0);
#define f(i, j) arr[ (i)*(amount+1) + (j) ]
        for(int j = 1; j <= amount; ++j)
            f(0, j) = INT_MAX - 1;
        for(int i = 1; i <= size; ++i)
            for(int j = 1; j <= amount; ++j)
                if( coins[i-1] > j )
                    f(i, j) = f(i-1, j);
                else
                    f(i, j) = min(f(i-1, j), f(i, j-coins[i-1]) +1);
        int rst = f(size, amount);
        return rst >= INT_MAX-1 ? -1 : rst;
    }
};



void test(vector<int> coins, int amount)
{
    cout << "input: amount=" << amount << ", coins=";
    outputVector(coins);
    int r = Solution().coinChange(coins, amount);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,5}, 11);
}


// Result 
//
// 2023-03-12: Runtime 112ms 52.51% Memory 43MB 35.25%, https://leetcode.com/problems/coin-change/submissions/913626966/, https://leetcode.com/problems/coin-change/solutions/1371738/c-recursion-dp-memoization-dp-tabulation/
// 2023-09-24: Runtime 92ms 32.62% Memory 41.35MB 7.01%, https://leetcode.cn/problems/coin-change/submissions/469182389


