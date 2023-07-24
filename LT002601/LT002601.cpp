#include <lt_help/lt.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if( size <= 1 )
            return size;
        int len = 1;
        for( int pos = 1; pos < size; ++pos)
            if( nums[len-1] != nums[pos] && len++ < pos )
                nums[len-1] = nums[pos];
        return len;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().removeDuplicates(nums);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({0,0,1,1,1,2,2,3,3,4});
}

// Result 
//
// 2023-02-16: Runtime 12ms 69.6% Memory 18.3MB 94.33%, https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/899189071/
// 2023-03-15: Runtime 9ms 82.60% Memory 18.2MB 94.36%, https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/915719485/
// 2023-07-24: Runtime 8ms 84.45% Memory 17.35MB 98.66%%, https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/449701020/


