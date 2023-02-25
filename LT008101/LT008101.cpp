#include <lt_help/lt.h>



class Solution {
//#define DBG(x)  x
#define DBG(x)
public:
    bool search(vector<int>& nums, int target) {
        int n0 = nums[0], low = 0, high = nums.size()-1;
        if ( n0 == target )
            return true;
        while( low <= high && nums[low] == n0)
            ++low;
        while( low <= high && nums[high] == n0)
            --high;
        if( low > high )
            return false;
        if( nums[low] > nums[high] )
        {   int k = findK(nums, low, high);            
            if( nums[low] <= target )
                high = k-1;
            else
                low  = k;
            DBG(cout << "test: low=" << low << ", high=" << high << ", k=" << k << endl;)
        }
        while( low <= high )
        {   int m = (low+high)/2; 
            DBG(cout << "low=" << low << ", high=" << high << ", m=" << m << ", nums[m]=" << nums[m] << endl;)
            if( nums[m] == target )
                return true;
            else if( nums[m] < target )
                low = m+1;
            else
                high = m-1;
        }
        return false;
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


void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);
    bool r = Solution().search(nums, target);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({2,5,6,0,0,1,2}, 0);
}


// Result 
//
// 2022-12-27: Runtime 3ms 94.98% Memory 14.1MB 51.34%, https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/866394129/


