#include <lt_help/lt.h>

// nums [a, b, c, d] ==> t
// map
//  [t-a] => 0
//  [t-b] => 1
//  ...

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {   
        map<int,int> _map;
        _map[target - nums[0]] = 0;

        for(int i = 1; i < (int)nums.size(); ++i)
        {   auto it = _map.find(nums[i]);
            if( it != _map.end() )
                return {it->second, i};
            _map[target - nums[i]] = i;
        }

        return {};
    }
};


void test(vector<int> input, int target)
{    
    cout << "input: nums=";  
    outputVector(input); 
    cout << ", target=" << target;
    vector<int> r = Solution().twoSum(input, target);
    cout << "; output: ";
    outputVector(r); 
    cout << ";" << endl;
}

int main(void)
{
    test({2, 7, 11, 15}, 9);
}

// Result 
//
// 2023-02-06: Runtime 11ms 87.54% Memory 11.1MB 19.19%, https://leetcode.com/problems/two-sum/submissions/892660439/



