#include <lt_help/lt.h>

class Solution {
public:
    // f(n) = f(n-1)*f(0) + f(n-2)*f(1) ... + f(0)*f(n-1) 
    int numTrees(int n) {
        vector<int> nums = {1, 1}; 
        int size = 2;
        while( size <= n ) {
            int num = 0;
            for(int i = 0;i < size; ++i )
                num += nums[i]*nums[size-i-1];
            nums.push_back(num);
            ++size;
        }          
        return nums[n];
    }
};


void test(int n)
{
    cout << "input: " << n;
    int r = Solution().numTrees(n);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(3);
    test(1);
}

// Result 
//
// 2022-11-22: Runtime 6ms 14.79% Memory 6MB 80.14%, https://leetcode.com/problems/unique-binary-search-trees/submissions/848092023/
// 2023-02-22: Runtime 2ms 51.76% Memory 6.2MB 15.44%, https://leetcode.com/problems/unique-binary-search-trees/submissions/902636326/
// 2023-09-25: Runtime 0ms 100% Memory 6.3 MB 7.47%, https://leetcode.cn/problems/unique-binary-search-trees/submissions/469411074/



