#include <lt_help/lt.h>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int count       = nums.size();
        m_min_dt        = INT_MAX;
        m_sum_closest   = 0;
        m_sum_target    = target;
        
        for(int i = count - 1; i >= 2 && m_min_dt > 0 ; --i )
        {   
            int a = nums[i];
            for(int j = i - 1; j >= 1 && m_min_dt > 0 ; --j )
            {
                int b = nums[j];
                int sum = a + b;
                int dt = target - sum;

                if( dt >= nums[j-1] )
                    _updatem_sum_closest(sum + nums[j-1]);
                else if( dt <= nums[0] )
                    _updatem_sum_closest(sum + nums[0]);
                else
                {
                    int l = 0, h = j - 1;
                    while( l <= h )
                    {
                        int m = (h+l)/2;
                        int v = nums[m];
                        if( v == dt )
                           return target;
                        else if( v < dt )
                            l = m + 1;
                        else 
                            h = m - 1;
                    }
                    
                    _updatem_sum_closest(sum + nums[l]);
                    _updatem_sum_closest(sum + nums[h]);
                }
            }
        }
        
        return m_sum_closest;
    }
    
    void _updatem_sum_closest(int sum){        
        int dt = abs( sum - m_sum_target );
        if( dt < m_min_dt )
        {   m_min_dt = dt;
            m_sum_closest = sum;
        }
    }
    
    int m_min_dt;
    int m_sum_closest;
    int m_sum_target;
};


void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);
    int r = Solution().threeSumClosest(nums, target);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({-1,2,1,-4}, 1);
}

// Result 
//
// 2022-11-03: Runtime 47ms 85.15% Memory 10.3MB 50.3%, https://leetcode.com/problems/3sum-closest/submissions/836069825/
// 2023-02-15: Runtime 55ms 61% Memory 10.3MB 50.79%, https://leetcode.com/problems/3sum-closest/submissions/898547017/


