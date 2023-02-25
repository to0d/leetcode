#include <lt_help/lt.h>



class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxVal = 0, lastVal = 0, sum = 0, size = nums.size();
        for(int i = 0 ; i < size; ++i)
        {   int v = nums[i];
            lastVal += i*v;
            sum += v;
        }
        maxVal = lastVal;
        for(int i = size-1 ; i > 0; --i)
        {   lastVal += sum - size*nums[i];
            maxVal = std::max(lastVal, maxVal);
        }
        
        return maxVal;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().maxRotateFunction(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({4,3,2,6});
}


// Result 
//
// 2023-01-04: Runtime 156ms 78.65% Memory 95.9MB 62.71%, https://leetcode.com/problems/rotate-function/submissions/873029319/


