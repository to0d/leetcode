#include <lt_help/lt.h>



class Solution {
public:
    int rob(vector<int>& nums) {
        
        switch( nums.size())
        {   case 0: return 0;
            case 1: return nums[0];
            case 2: return std::max(nums[0],nums[1]);
        }
        
        return std::max( nums[0] + robLine(nums, 2, nums.size() - 3), 
                        robLine(nums, 1, nums.size() - 1) );
    }
    
    int robLine(vector<int>& nums, int from, int size) {
        
        if( size == 0 )
            return 0;
        else if( size == 1)
            return nums[from];
        
        //Duduce: n3 = max( num[i] + n2, n1 )
        int n1 = 0;
        int n2 = nums[from];
        int n3 = 0;
        int i  = 2 + from;
        int r  = 0;
        int to = from + size;
        
        for(; i <= to; ++i, n1=n2, n2=n3 )
            r = n3 = std::max( n1 + nums[i-1], n2 );
        
        return r;
    }
};

void test(vector<int> nums)
{
    int output = Solution().rob(nums);
    cout << "input: ";  
    outputVector(nums);
    cout << "; output: " << output << endl;
}


int main(void)
{
    test({2,3,2}); 
}

// Result 
//
// 2022-11-14: Runtime 0ms 100% Memory 7.6MB 100%, https://leetcode.com/problems/house-robber-ii/submissions/842998402/

