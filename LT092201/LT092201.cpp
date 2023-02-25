#include <lt_help/lt.h>

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int pos1 = 0, pos2 = 1, size = nums.size();
        while( pos2 < size )
        {   if(nums[pos2] % 2 == 1)
                pos2 += 2;
            else
            {   while( (pos1+1) < size )
                {   if(nums[pos1] % 2 != 0)
                        break;
                    pos1 += 2;
                }
                int v = nums[pos1];
                nums[pos1] = nums[pos2];
                nums[pos2] = v;
            }
        }

        return nums;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().sortArrayByParityII(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   
    test({4,2,5,7});
}


// Result 
//
// 2022-12-03: Runtime 61ms 5.29% Memory 21.3MB 98.80%, https://leetcode.com/problems/sort-array-by-parity-ii/submissions/853708440/
// 2023-02-24: Runtime 19ms 88.46% Memory 21.6MB 45.33%, https://leetcode.com/problems/sort-array-by-parity-ii/submissions/904198125/



