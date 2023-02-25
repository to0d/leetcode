#include <lt_help/lt.h>



class Solution {
//#define DBG(x)  x
#define DBG(x)
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if( size == 1 || nums[0] < nums[size-1] ) return nums[0];
        if( size == 2 ) return nums[1];
        int low = 0, high = nums.size()-1;
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
    test({3,4,5,1,2});
}


// Result 
//
// 2023-01-03: Runtime 17ms 5.22% Memory 10.1MB 78.54%, https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/870522006/



