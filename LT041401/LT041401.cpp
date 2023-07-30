#include <lt_help/lt.h>


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int vals[3], count = 0;
        for(int num : nums)
        {   for(int i = 0;i < 3; ++i )
            {   if( i >= count )
                {   vals[count++] = num;
                    break;
                }
                if( vals[i] == num )    // ignore same number
                    break;
                if( vals[i] < num )     // swap numbers
                {   int t = vals[i];
                    vals[i] = num;
                    num = t;
                }
            }
        }
        return count == 3 ? vals[2] : vals[0];
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().thirdMax(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({3,2,1});
}

// Result 
//
// 2022-11-21: Runtime 4ms 82.61% Memory 6.1MB 96.27%, https://leetcode.com/problems/third-maximum-number/submissions/846975714/
// 2023-07-30: Runtime 0ms 100% Memory 8.63MB 71.94%, https://leetcode.cn/problems/third-maximum-number/submissions/

