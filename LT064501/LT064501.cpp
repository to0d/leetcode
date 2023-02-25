#include <lt_help/lt.h>




class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        int swap = -1, dup = -1;
        for(int i = 0; i< size; ++i )
        {   if(nums[i] == (i+1))
                continue;
            swap = nums[i];
            nums[i] = -1;
            while( swap != -1 )
            {   int v = nums[swap-1];
                // cout << "swap: " << swap << ", miss=" << miss << ", v=" << v << ", nums="; for(auto v : nums ) cout << v << ", "; cout << endl;
                if( v == swap )
                {   dup = swap;
                    swap = -1;
                }
                else
                {   nums[swap-1] = swap;
                    swap = v;
                }
            }
        }
        int miss = -1;
        for(int i = 0; i< size && miss == -1; ++i )
            if( nums[i] == -1)
                miss = i +1;

        //for(auto v : nums ) cout << v << ", "; cout << endl;
        vector<int> rst = {dup, miss};
        return rst;      
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().findErrorNums(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({1,2,2,4});
}


// Result 
//
// 2022-12-01: Runtime 30ms 83.59% Memory 21.4MB 89.65%, https://leetcode.com/problems/set-mismatch/submissions/852382060/


