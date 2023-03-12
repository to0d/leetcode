#include <lt_help/lt.h>

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        _sortEvenOdd(nums, 0, true);
        _sortEvenOdd(nums, 1, false);
        return nums;
    }
    
    void _sortEvenOdd(vector<int>& nums, int pos, bool inc) {
        for (int i = nums.size(); i > pos; i -= 2)
        {   int update = 0;
            for (int j = pos + 2; j < i; j += 2)
            {   if( (inc && nums[j] < nums[j-2]) || !inc && nums[j] > nums[j-2] )
                {   int v = nums[j-2];
                    nums[j-2] = nums[j];
                    nums[j] = v;
                    ++update;
                }
            }
            if( update == 0 )
                break;
        }
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().sortEvenOdd(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   
    test({4,1,2,3});
}


// Result 
//
// 2022-12-03: Runtime 26ms 5.56% Memory 11.9MB 95.37%, https://leetcode.com/problems/sort-even-and-odd-indices-independently/submissions/853714814/
// 2023-02-18: Runtime 7ms 75.28% Memory 12MB 91%, https://leetcode.com/problems/sort-even-and-odd-indices-independently/submissions/900113661/
// 2023-03-10: Runtime 3ms 96.53% Memory 11.9MB 89.6%, https://leetcode.com/problems/sort-even-and-odd-indices-independently/submissions/912732276/



