#include <lt_help/lt.h>



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        m_map.clear();
        return _find(nums, 0, nums.size(), target);
    }
    
    int _find(vector<int>& nums, int idx, int len, int target) 
    {   int count = 0;
        if( idx == (len-1) )
        {   int val = nums[idx];
            if( val == target )
                count++;
            if( (-val) == target )
                count++;
            return count;
        }

        auto it = m_map.find(idx);
        if( it != m_map.end() )
        {   auto it2 = it->second.find(target);
            if( it2 != it->second.end() )
            {   return it2->second;
            }
        }
        
        count += _find(nums, idx+1, len, target + nums[idx]);
        count += _find(nums, idx+1, len, target - nums[idx]);
        
        if( it != m_map.end() )
        {   it->second[target] = count;
        }
        else
        {   unordered_map<int,int> _map;
            _map[target] = count;
            m_map[idx] = _map;
        }
        
        return count;
    }
   
    unordered_map<int,unordered_map<int,int>> m_map;
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


