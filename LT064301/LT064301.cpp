#include <lt_help/lt.h>



class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        int lastSum = 0, maxSum;
        for(int i = 0;i < k; ++i)
            lastSum += nums[i];
        int dsize = size - k;
        maxSum = lastSum;
        for(int i = 0;i < dsize; ++i)
        {   lastSum = lastSum - nums[i] + nums[k+i];
            maxSum  = std::max(maxSum, lastSum);
        }
        return ((double)maxSum) / k;
    }
};


void test(vector<int> nums, int k)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    double r = Solution().findMaxAverage(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({1,12,-5,-6,50,3}, 4);
}


// Result 
//
// 2023-01-10: Runtime 151ms 99.80% Memory 109.4MB 99.75%, https://leetcode.com/problems/maximum-average-subarray-i/submissions/875486415/

