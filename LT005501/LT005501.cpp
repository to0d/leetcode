#include <lt_help/lt.h>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return true;

        vector<int> jumpResult(nums.size(), 0);
        // optimize a: dead point
        for(int pos = nums.size() - 2, min = 1; pos >= 0 && nums[pos] < min; ++min, --pos)
            jumpResult[pos] = -1;

        return canJumpAt(nums, jumpResult, 0) > 0;
    }
    
    int canJumpAt(vector<int>& nums, vector<int>& jumpResult, int pos){
        if(( pos + 1) >= jumpResult.size() )
            return 1;
        
        int rj = jumpResult[pos];
        if( rj == 0 )
        {   //optimize b
            int n = std::min( nums[pos], (int)(nums.size() - pos - 1) );
            for(int i = n; i > 0 && rj == 0 ; --i)
                if( canJumpAt(nums, jumpResult, pos + i ) > 0 )
                    rj = 1;

            if(rj == 0) 
                rj = -1;

            jumpResult[pos] = rj;
        }
        
        return rj;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    bool r = Solution().canJump(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({2,3,1,1,4});
}

// Result 
//
// 2022-11-19: Runtime 191ms 23.7% Memory 51.2MB 8.32%, https://leetcode.com/problems/jump-game/submissions/846138659/
// 2023-02-17: Runtime 78ms 39.34% Memory 51.2MB 8.55%, https://leetcode.com/problems/jump-game/submissions/899820431/


