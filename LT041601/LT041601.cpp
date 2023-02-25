#include <lt_help/lt.h>




class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        if( nums.size() <= 1)
            return false;
        
        sums.clear();
        int total = 0;
        for(int num : nums)
        {   total += num;
            sums.push_back(total);
        }
        
        int totalSum = sums[nums.size()-1];
        if( (totalSum%2) != 0 )
            return false;

        return _find(nums.size(), totalSum/2, nums);
    }

    bool _find(int n, int target, vector<int>& nums)
    {
        // cout << "n=" << n << ", t=" << target << endl;
        if( n <= 0 || sums[n-1] < target )
            return false;

        int v = nums[n-1];
        if( target == 0 || sums[n-1] == target ) 
        {   return true;
        }
        
        if( target < v)
        {   return _find(n-1, target, nums);
        }

        return _find(n-1, target-v, nums) || _find(n-1, target, nums);
    }
    
private:
    vector<int> sums;
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
    test({2,2,3,5});
}

// Result 
//
