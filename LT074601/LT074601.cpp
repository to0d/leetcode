#include <lt_help/lt.h>

class Solution {
public:
    // f(n) = min(f(n-2),f(n-1))+v(n)
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size(), f1 = cost[0], f2 = cost[1];
        for(int i = 2 ; i < size; ++i)
        {   int fx = std::min(f1, f2)+cost[i];
            f1 = f2;
            f2 = fx;
        }
        return std::min(f1, f2);
    }
};



void test(vector<int> cost)
{
    cout << "input: ";
    outputVector(cost);
    int r = Solution().minCostClimbingStairs(cost);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({10,15,20});
}


// Result 
//
// 2022-12-22: Runtime 7ms 70.99% Memory 13.7MB 83.80%, https://leetcode.com/problems/min-cost-climbing-stairs/submissions/863767907/
// 2023-03-12: Runtime 5ms 71.53% Memory 13.6MB 83.92%, https://leetcode.com/problems/min-cost-climbing-stairs/submissions/913493842/



