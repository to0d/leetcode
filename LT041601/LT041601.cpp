#include <lt_help/lt.h>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if( nums.size() <= 1)
            return false;
        int sum = 0;
        for(int num : nums)
            sum += num;
        if( (sum%2) != 0 )
            return false;
        int target = sum/2;
        unordered_set<int> _set, _set2;
        _set.insert(0);
        for(int num : nums)
        {   _set2.clear();
            for(int sum : _set)
            {   int sum2 = sum + num;
                if( sum2 == target )
                    return true;
                _set2.insert(sum2);
                _set2.insert(sum);
            }
            _set.swap(_set2);
        }
        return false;
    }
};



void test(vector<int> nums)
{
    bool out = Solution().canPartition(nums);
    cout << "input: ";
    outputVector(nums);
    cout << "; output: " << out;
    cout << endl;
}

int main(void)
{
    test({1,5,11,5});
}

// Result 
//
// 2023-03-12: Runtime 840ms 8.27% Memory 146.5MB 13.45%, https://leetcode.com/problems/partition-equal-subset-sum/submissions/913300974/

