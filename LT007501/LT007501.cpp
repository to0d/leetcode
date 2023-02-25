#include <lt_help/lt.h>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k = 0;
        while( i <= j )
        {   switch( nums[i] )
            {   case 0:
                    if( i == k )
                    {   ++i;
                        ++k;
                    }
                    else 
                        swap( nums, i, k++ );
                    break;
                case 1:
                    ++i; 
                    break;
                default: // 2 == nums[i]
                    swap( nums, i, j-- );
            }
        }
    }

    void swap(vector<int>& nums, int a, int b){
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    Solution().sortColors(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << ";" << endl;
}

int main(void)
{
    test({2,0,2,1,1,0});
}

// Result 
//
// 2022-11-23: Runtime 6ms 24.10% Memory 8.3MB 73.46%, https://leetcode.com/problems/sort-colors/submissions/848338693/
// 2023-02-18: Runtime 3ms 56.32% Memory 8.3MB 73.34%, https://leetcode.com/problems/sort-colors/submissions/900096025/



