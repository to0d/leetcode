#include <lt_help/lt.h>



class Solution {
public:

    vector<string> summaryRanges(vector<int>& nums) 
    {
        int len = nums.size();
        
        vector<string> res;
        if( len == 0 )
            return res;
        
        int from = nums[0];
        int to = from;
        int v = 0;
        for(int pos = 1; pos < len ; ++pos, to = v)
        {
            if( (v = nums[pos]) != (to + 1))
            {
                res.push_back(toString(from, to));
                from = v;
            }
        }

        res.push_back(toString(from, to));
        return res;
    }
    
    string toString(int from, int to)
    {
        if(from == to )
            return to_string(from);
        else
            return to_string(from) + "->" + to_string(to); 
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<string> r = Solution().summaryRanges(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({0,1,2,4,5,7});
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 6.9MB 35.37%, https://leetcode.com/problems/summary-ranges/submissions/846329694/
