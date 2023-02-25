#include <lt_help/lt.h>



class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy;
        std::copy(heights.begin(), heights.end(), std::back_inserter(copy));
        std::sort(copy.begin(), copy.end());
        int count = 0, size = heights.size();
        for(int i = 0; i < size; ++i )
            if( copy[i] != heights[i])
                ++ count;
        return count;
    }
};


void test(vector<int> heights)
{
    cout << "input: ";
    outputVector(heights);
    int r = Solution().heightChecker(heights);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,1,4,2,1,3});
}


// Result 
//
// 2022-12-14: Runtime 0ms 100% Memory 8.2MB 30.83%, https://leetcode.com/problems/height-checker/submissions/859441251/



