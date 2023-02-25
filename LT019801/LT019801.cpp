#include <lt_help/lt.h>

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if( size < 2)
            return size == 0 ? 0 : nums[0];

        //Duduce: n3 = max( num[i] + n2, n1 )
        int n1(0), n2(nums[0]), n3(0), r=0;
        for(int i = 2; i <= size; ++i, n1=n2, n2=n3 )
            r = n3 = std::max( n1 + nums[i-1], n2 );

        return r;
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

