#include <lt_help/lt.h>

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = ops.size(), minM = m, minN = n;
        for( int i = 0; i < row; ++i )
        {   vector<int>& op = ops[i];
            minM = std::min(minM, op[0]);
            minN = std::min(minN, op[1]);
        }

        return minM*minN;
    }
};



void test(int m, int n, vector<vector<int>> ops)
{
    cout << "input: m=" << m << ", n=" << n << ", ops=";
    outputVector(ops);
    int r = Solution().maxCount(m, n, ops);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3, 3, {{2,2},{3,3}});
}

// Result 
//
// 2022-11-22: Runtime 20ms 6.67% Memory 7.4MB 33.33%, https://leetcode.com/problems/range-addition-ii/submissions/847785646/
// 2023-02-25: Runtime 12ms 58.54% Memory 11.1MB 65.45%, https://leetcode.com/problems/range-addition-ii/submissions/904437155/


