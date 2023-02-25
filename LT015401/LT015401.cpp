#include <lt_help/lt.h>



class Solution {
//#define DBG(x)  x
#define DBG(x)
public:
    int findMin(vector<int>& nums) {
        int n0 = nums[0], low = 0, high = nums.size()-1;
        while( low <= high && nums[low] == n0)
            ++low;
        --low;
        while( low <= high && nums[high] == n0)
            --high;
        DBG(cout << "low=" << low << ", high=" << high << endl;)
        if( low > high || nums[low] <= nums[high])
            return n0;
        int k = findK(nums, low, high);
        return nums[k];
    }
    int findK(vector<int>& nums, int low, int high)
    {   int n0 = nums[low];
        while( low <= high )
        {   int m = (low+high)/2;    
            DBG(cout << "findK: low=" << low << ", high=" << high << ", m=" << m << ", nums[m]=" << nums[m] << endl;)
            if( nums[m] >= n0 )
                low = m+1;
            else
                high = m-1;
        }
        DBG(cout << "findK: low=" << low << ", high=" << high << endl;)
        return low;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().findMin(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({2,2,2,0,1});
}


// Result 
//
// 2023-01-03: Runtime 10ms 27.15% Memory 12.4MB 27.74%, https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/submissions/870530462/




