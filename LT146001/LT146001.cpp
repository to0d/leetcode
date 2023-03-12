#include <lt_help/lt.h>

class Solution {
public:
    bool canBeEqual(vector<int>& arr1, vector<int>& arr2) {
        int max1, min1, sum1, max2, min2, sum2;
        _scan(arr1, max1, min1, sum1);
        _scan(arr2, max2, min2, sum2);
        if( max1 != max2 || min1 != min2 || sum1 != sum2 )
            return false;
        int size = arr1.size();
        for(int i = 0;i < size; ++i)
            if( _bubble(arr1, i) != _bubble(arr2, i))
                return false;
        return true;
    }
    
    void _scan(vector<int>& arr, int _max, int _min, int _sum) {
        _max = INT_MIN, _min = INT_MAX, _sum = 0;
        for(int v : arr )
        {   _max = std::max(_max, v);
            _min = std::min(_min, v);
            _sum += v;
        }
    }
    
    int _bubble(vector<int>& arr, int i) {
        for(int j = arr.size() - 1; j > i; --j)
            if( arr[j] < arr[j-1])
            {   int v = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = v;
            }
        return arr[i];
    }
};



void test(vector<int> target, vector<int> arr)
{
    cout << "input: target=";
    outputVector(target);
    cout << ", arr=";
    outputVector(arr);
    bool r = Solution().canBeEqual(target, arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,3,4}, {2,4,1,3});
}


// Result 
//
// 2022-12-15: Runtime 103ms 5.2% Memory 14.5MB 63.47%, https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/submissions/860215688/
// 2023-02-25: Runtime 95ms 5.6% Memory 14.5MB 31.86%, https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/submissions/904215408/
// 2023-03-11: Runtime 103ms 5.8% Memory 14.5MB 30.98%, https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/submissions/912982441/



