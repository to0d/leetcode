#include <lt_help/lt.h>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        for(int i = size-1 ; i >= 0; --i)
            if( citations[i] < (size - i))
                return size - i - 1;    

        return size;
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
