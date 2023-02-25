#include <lt_help/lt.h>

bool less_interval(const vector<int>& a, const vector<int>& b){   
    int d = a[0] - b[0];
    if( d == 0 )
        d = a[1] - b[1];
    return d < 0;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> pairs;
        for(int v : arr )
        {   int n = numOf1(v);
            pairs.push_back({n, v});
        }

        sort(pairs.begin(), pairs.end(), less_interval);
        
        vector<int> rst;
        for(vector<int> & v : pairs )
            rst.push_back(v[1]);
        
        return rst;
    }

    int numOf1(int v) {  
        int n = 0;
        for( ; v > 0; v = v >> 1)
            if( v & 1 == 1 )
                ++n;
        return n;
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    vector<int> r = Solution().sortByBits(arr);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({0,1,2,3,4,5,6,7,8});
}


// Result 
//
// 2022-12-12: Runtime 48ms 5.9% Memory 13.4MB 5.19%, https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/submissions/858686296/
// 2023-02-25: Runtime 20ms 17.54% Memory 12.5MB 5.58%, https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/submissions/904210774/



