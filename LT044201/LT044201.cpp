#include <lt_help/lt.h>



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> rst;
        int i = 0, size = nums.size();
        while( i < size )
        {   int n0 = nums[i];
            if( n0 == 0 || n0 == (i+1))
            {   i++;
                continue;
            }

            int n1 = nums[n0-1];
            if( n1 == n0 )
            {   rst.push_back(n0);
                nums[n0-1] = 0;
                nums[i] = 0;
                i++;
                continue;
            }

            nums[n0-1] = n0;
            nums[i] = n1; 
        }
        return rst;
    }
};

void test(vector<int> nums)
{
    cout << "input: "; 
    outputVector(nums); 
    vector<int> r = Solution().findDuplicates(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({4,3,2,7,8,2,3,1});
}

// Result 
//
// 2023-01-28: Runtime 59ms 84.89% Memory 33.6MB 58.77%, https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/886887791/


