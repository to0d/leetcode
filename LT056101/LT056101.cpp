#include <lt_help/lt.h>

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < size; i += 2)
            sum += nums[i];
        return sum;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().arrayPairSum(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({6,2,6,5,1,2});
}

// Result 
//
// 2022-11-19: Runtime 145ms 5% Memory 8.7MB 36.25%, https://leetcode.com/problems/array-partition/submissions/846383551/
// 2023-02-24: Runtime 61ms 52.13% Memory 28.2MB 92.83%, https://leetcode.com/problems/array-partition/submissions/904172912/
