#include <lt_help/lt.h>

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        _sortEvenOdd(nums, 0, true);
        _sortEvenOdd(nums, 1, false);
        return nums;
    }
    
    void _sortEvenOdd(vector<int>& nums, int pos, bool inc) {
        int size = nums.size();
        while ( pos < size)
        {   int update = 0;
            int pos2 = pos + 2;
            while (pos2 < size)
            {   if( (inc && nums[pos2] < nums[pos2-2]) || !inc && nums[pos2] > nums[pos2-2] )
                {   int v = nums[pos2-2];
                    nums[pos2-2] = nums[pos2];
                    nums[pos2] = v;
                    ++update;
                }
                pos2 += 2;
            }
            if( update == 0 )
                break;
            size -= 2;
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



