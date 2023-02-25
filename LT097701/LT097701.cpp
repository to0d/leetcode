#include <lt_help/lt.h>



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int max_neg_pos = -1;
        for(int i = 0; i < size; ++i)
        {   if(nums[i] < 0 )
                max_neg_pos = i;
            nums[i] = nums[i]*nums[i];
        }
        if( max_neg_pos == -1)
            return nums;
        if( max_neg_pos > 0 )
            std::reverse(nums.begin(), nums.begin()+max_neg_pos+1);
        if( max_neg_pos == (size -1))
            return nums;
        int pos1 = 0, pos2 = max_neg_pos+1;
        vector<int> rst;
        while( pos1 <=max_neg_pos && pos2 < size )
        {   if( nums[pos1] < nums[pos2] )
                rst.push_back(nums[pos1++]);
            else
                rst.push_back(nums[pos2++]);
        }
        while( pos1 <=max_neg_pos  )
            rst.push_back(nums[pos1++]);
        while( pos2 < size  )
            rst.push_back(nums[pos2++]);
        return rst;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().sortedSquares(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({-4,-1,0,3,10});
}


// Result 
//
// 2022-12-07: Runtime 43ms 51.48% Memory 26.9MB 17.45%, https://leetcode.com/problems/squares-of-a-sorted-array/submissions/855878074/



