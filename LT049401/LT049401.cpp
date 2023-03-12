#include <lt_help/lt.h>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> _map1, _map2;
        _map1[0]=1;
        for(int num : nums )
        {   _map2.clear();
            for(auto it = _map1.begin(); it != _map1.end(); ++it)
            {   int sum = it->first, count = it->second;
                _map2[sum+num] += count;
                _map2[sum-num] += count;
            }
            _map1.swap(_map2);
        }
        return _map1[target];
    }
};



void test(vector<int> nums, int target)
{
    cout << "input: nums=";
    outputVector(nums); 
    cout << ", target=" << target;
    int r = Solution().findTargetSumWays(nums, target);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test({1,1,1,1,1}, 3);
}

// Result 
//
// 2023-01-08: Runtime 237ms 40.71% Memory 55.7MB 13.95%, https://leetcode.com/problems/target-sum/submissions/873804038/
// 2023-03-11: Runtime 166ms 43.62% Memory 34.9MB 22.81%, https://leetcode.com/problems/target-sum/submissions/913266458/


