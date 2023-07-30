#include <lt_help/lt.h>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size(), low = 0, high = size-1;
        while( low <= high )
        {   int m = (low+high)/2, v = citations[m] - (size - m);
            if ( v > 0 )
                high = m - 1;
            else if(v == 0 )
                return size - m;
            else 
                low = m + 1;
        }
        return size-high-1;
    }
};



void test(vector<int> citations)
{
    cout << "input: ";
    outputVector(citations); 
    int r = Solution().hIndex(citations);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({0,1,3,5,6});
}

// Result 
//
// 2022-11-22: Runtime 27ms 26.74% Memory 18.6MB 90.94%, https://leetcode.com/problems/h-index-ii/submissions/847758195/
// 2023-02-22: Runtime 21ms 59.96% Memory 18.7MB 54.87%, https://leetcode.com/problems/h-index-ii/submissions/902730248/
// 2023-07-29: Runtime 12ms 88.61% Memory 17.70MB 63.76%, https://leetcode.cn/problems/h-index-ii/submissions/451268528/

