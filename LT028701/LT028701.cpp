#include <lt_help/lt.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size(), l = 0, h = size-1, ans = -1;
        while( l <= h ){
            int m = (l+h)/2, cn = 0;
            for( int num : nums )
                cn += num <= m;
            if( cn <= m )
                l = m + 1;
            else {
                h = m -1;
                ans = m;
            }
        }
        return ans;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findDuplicate(nums);
    cout << "; output: " << r << endl;
}


int main(void)
{
    test({1,3,4,2,2});
}

// Result 
//
// 2023-02-17: Runtime 113ms 83.7% Memory 61.3MB 34.89%, https://leetcode.com/problems/find-the-duplicate-number/submissions/899788372/
// 2023-09-27: Runtime 84ms 77.59% Memory 60.2MB 15.29%, https://leetcode.cn/problems/find-the-duplicate-number/submissions/469971179/

