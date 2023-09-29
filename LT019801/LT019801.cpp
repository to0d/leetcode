#include <lt_help/lt.h>

class Solution {
public:
    // fun(i) = max( N(i) + f(n-2), f(n-1) )
    //        = 0    when i <= 0
    //        = N(0) when i == 1
    int rob(vector<int>& nums) {
        int a = 0, b = 0, n = nums.size();
        for(int i = 0;i < n; ++i){
            int c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;
    }
};


void test(vector<int> nums)
{
    int output = Solution().rob(nums);
    cout << "input: ";  
    outputVector(nums);
    cout << "; output: " << output << endl;
}


int main(void)
{
    test({2,7,9,3,1}); 
}

// Result 
//
// 2022-11-14: Runtime 4ms 28.15% Memory 7.7MB 53.77%, https://leetcode.com/problems/house-robber/submissions/842995826/
// 2023-02-20: Runtime 0ms 100% Memory 7.7MB 61.20%, https://leetcode.com/problems/house-robber/submissions/901595719/
// 2023-03-12: Runtime 0ms 100% Memory 7.7MB 86.64%, https://leetcode.com/problems/house-robber/submissions/913495302/
// 2023-09-27: Runtime 0ms 100% Memory 7.9MB 23.30%, https://leetcode.cn/problems/house-robber/submissions/469942553/


