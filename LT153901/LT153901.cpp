#include <lt_help/lt.h>



#define TRACE(x)
//#define TRACE(x) x
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        TRACE(cout << "k=" << k << endl;)
        int size = arr.size();
        int findPos = -1;
        if( _miss(arr, size-1) < k )
            findPos = size-1;
        else if (_miss(arr, 0) >= k)
            return k;
        else
        {   int low = 0, high = size-1;
            while( low <= high && low >=0 && high < size && findPos == -1)
            {   int m = (low+high)/2;
                TRACE(cout << "low=" << low << ", high=" << high << ", m=" << m << endl;)
                int n = _miss(arr, m);
                if( n >= k )
                    high = m-1;
                else if( n < k )
                {   if( _miss(arr, m+1) >= k )
                        findPos = m;
                    else
                        low = m + 1;
                }
            }
            if( findPos == -1 )
                findPos = high;
        }
        TRACE(cout << "findPos=" << findPos << endl;)
        return arr[findPos] + k - _miss(arr, findPos);
    }
    int _miss(vector<int>& arr, int pos)
    {   TRACE(cout << "_miss: pos=" << pos << ", val=" << (arr[pos] - pos - 1) << endl;)
        return arr[pos] - pos - 1;
    }
};


void test(vector<int> arr, int k)
{
    cout << "input: k=" << k << ", arr=";
    outputVector(arr);
    int r = Solution().findKthPositive(arr, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({2,3,4,7,11}, 5);
}


// Result 
//
// 2022-12-15: Runtime 5ms 67.40% Memory 9.6MB 36.88%, https://leetcode.com/problems/kth-missing-positive-number/submissions/859976427/



