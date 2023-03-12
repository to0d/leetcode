#include <lt_help/lt.h>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++ )
        {   int v = nums[i];
            if( v == 0 || v == (i+1))
                continue;
            nums[i] = 0;
            while( v != 0 )
            {   int vv = nums[v-1];
                if( vv == v )
                    break;
                nums[v-1] = v;
                v = vv;
            }
        }
        vector<int> r;
        for( int i = 0; i < size; i++ )
            if(nums[i] == 0 )
                r.push_back(i+1);
        return r;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().findDisappearedNumbers(nums);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test({4,3,2,7,8,2,3,1});
}

// Result 
//
// 2022-11-21: Runtime 121ms 34.48% Memory 33.7MB 87.8%, https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/846977828/
// 2023-02-24: Runtime 56ms 84.86% Memory 33.7MB 86.82%, https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/904145014/
// 2023-03-11: Runtime 58ms 77.62% Memory 33.5MB 95.44%, https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/913273019/



