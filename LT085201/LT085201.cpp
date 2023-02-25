#include <lt_help/lt.h>



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int from = 0, len = arr.size();
        while ( len > 0 )
        {
            if( len == 1 )
                return from;
            
            if( len == 2 )
                return (arr[from] > arr[from+1]) ? from : (from+1);
            
            int m = from + len / 2;
            if( arr[m-1] < arr[m] )
            {   if( arr[m] < arr[m+1] )
                {   len -= m + 1 - from; 
                    from = m + 1;
                }
                else
                    return m;
            }
            else 
            {   if( arr[m] > arr[m+1] )
                    len = m - from;
                else
                    return m;
            }
        }
        return -1;
    }
};


void test(vector<int> arr)
{
    cout << "input: "; 
    outputVector(arr); 
    int r = Solution().peakIndexInMountainArray(arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({0,10,5,2});
}

// Result 
//
// 2023-01-30: Runtime 115ms 83.93% Memory 59.8MB 23.86%, https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/888116984/


