#include <lt_help/lt.h>



class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if( nums.size() <= 1 )
            return 0;
        k = std::abs(k);
        int max_num = nums[0], min_num = nums[0];
        for(int n : nums )
            if( n > max_num )
                max_num = n;
            else if( n < min_num )
                min_num = n;
        int diff = max_num - min_num;
        return diff <= 2*k ? 0 : (diff - 2*k);
    }
};


void test(vector<int> nums, int k)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    int r = Solution().smallestRangeI(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({0,10}, 2);
}


// Result 
//
// 2022-12-05: Runtime 16ms 76.53% Memory 15.5MB 61.55%, https://leetcode.com/problems/smallest-range-i/submissions/854755645/



