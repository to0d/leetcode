#include <lt_help/lt.h>



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos1 = 0, pos2= nums.size()-1;        
        while( pos1 < pos2 )
        {
            if ((nums[pos1] % 2) == 0)
            {   ++pos1;
                continue;
            }
            if ((nums[pos2] % 2) == 1)
            {   --pos2;
                continue;
            }
            int v = nums[pos2];
            nums[pos2] = nums[pos1];
            nums[pos1] = v;
            ++pos1;
            --pos2;
        }
        return nums;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().sortArrayByParity(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   
    test({3,1,2,4});
}


// Result 
//
// 2022-12-05: Runtime 7ms 91.33% Memory 16.3MB 33.22%, https://leetcode.com/problems/sort-array-by-parity/submissions/854750986/



