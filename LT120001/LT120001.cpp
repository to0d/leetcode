#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> rst;
        int size = arr.size();
        if( size <= 1 )
            return rst;
        std::sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for(int i = 1; i < size; ++i)
            minDiff = std::min(minDiff, arr[i]-arr[i-1]);
        for(int i = 1; i < size; ++i)
            if( (arr[i]-arr[i-1]) == minDiff )
                rst.push_back({arr[i-1], arr[i]});
        return rst;
    }
};


void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    vector<vector<int>> r = Solution().minimumAbsDifference(arr);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({4,2,1,3});
}


// Result 
//
// 2022-12-12: Runtime 69ms 95.9% Memory 32.3MB 54.9%, https://leetcode.com/problems/minimum-absolute-difference/submissions/858400498/



