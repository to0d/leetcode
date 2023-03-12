#include <lt_help/lt.h>

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i <= n; ++i)
        {   long square = i*i;
            if( square <= n )
                squares.push_back(square);
            else
                break;
        }
        return coinChange(squares, n);  // refer LT032201.cpp
    }
    
    // f(n, m) = f(n-1, m)                              when coins[n-1] > m 
    //         = min(f(n-1, m),  f(n, m-coins[n-1]))    otherwise
#define dpf(i, j) dp[(i)*(amount+1) + (j)]
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<int> dp( (size+1)*(amount+1), 0);
        for(int i = 0; i <= size; ++i)
            dpf(i, 0) = 0; 
        for(int j = 0; j <= amount; ++j)
            dpf(0, j) = INT_MAX-1;       
        for(int i = 1; i <= size; ++i) 
            for(int j = 1; j <= amount; ++j)
                if( coins[i-1] > j )
                    dpf(i, j) = dpf(i-1, j);
                else  
                    dpf(i, j) = min(dpf(i-1, j), 1 + dpf(i, j - coins[i-1]));
        int rst = dpf(size, amount); 
        return rst == INT_MAX-1 ? -1 : rst;
    }
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().numSquares(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(12);
}


// Result 
//
// 2023-03-12: Runtime 514ms 13% Memory 137.3MB 7.30%, https://leetcode.com/problems/perfect-squares/submissions/913669926/


