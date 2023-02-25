#include <lt_help/lt.h>

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
            return true;
        
        // optimize a: dead point
        vector<int> jumpResult(nums.size(), 0);  
        for(int min = 1, pos = nums.size() - 2; pos >= 0 && nums[pos] < min; ++min, --pos)
            jumpResult[pos] = -1;

        return canJumpAt(nums, jumpResult, 0) - 1;
    }
    
    int canJumpAt(vector<int>& nums, vector<int>& jumpResult, int pos){   
        if(( pos + 1) >= jumpResult.size() )
            return 1;
        
        int rj = jumpResult[pos];
        if( rj == 0 )
        {   //optimize b
            int n = std::min( nums[pos], (int)(nums.size() - pos - 1) );
            for(int i = n; i > 0 ; --i)
            {   int r = canJumpAt(nums, jumpResult, pos + i );
                if (r > 0 )
                    rj = rj == 0 ? r : std::min(rj, r);
            }

            if(rj == 0) 
                rj = -1;
            else
                rj++;

            jumpResult[pos] = rj;
        }

        return rj;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    bool r = Solution().jump(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({2,3,1,1,4});
}

// Result 
//
// 2022-11-24: Runtime 280ms 36.39% Memory 17.6MB 17.69%, https://leetcode.com/problems/jump-game-ii/submissions/848912151/
// 2023-02-17: Runtime 290ms 31.20% Memory 17.6MB 16.69%, https://leetcode.com/problems/jump-game-ii/submissions/899800081/

