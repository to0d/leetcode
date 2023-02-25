#include <lt_help/lt.h>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // **Deduce:**  Sum = n(n+1)/2
        int size = nums.size();
        return size*(size+1)/2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().missingNumber(nums);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({9,6,4,2,3,5,7,0,1});
}

// Result 
//
// 2022-11-19: Runtime 63ms 7.27% Memory 18MB 24.94%, https://leetcode.com/problems/missing-number/submissions/846334363/
// 2023-02-19: Runtime 19ms 77.14% Memory 17.9MB 94.59%, https://leetcode.com/problems/missing-number/submissions/900662898/



