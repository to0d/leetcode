#include <lt_help/lt.h>



class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = nums.size();
        if( size == 0 )
            return nums;
        vector<int> copy;
        std::copy(nums.begin(), nums.end(), std::back_inserter(copy));
        std::sort(copy.begin(), copy.end());
        unordered_map<int,int> _map;
        int last = copy[0]-1;
        for(int i = 0; i < size; ++i )
        {   int val = copy[i];
            if( val != last)
            {   _map[val] = i;
                last = copy[i];
            }
        }
        for(int i = 0; i < size; ++i )
            nums[i] = _map.find(nums[i])->second;
        return nums;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().smallerNumbersThanCurrent(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({8,1,2,2,3});
}


// Result 
//
// 2022-12-13: Runtime 10ms 79.5% Memory 10.7MB 6.63%, https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/858937775/



