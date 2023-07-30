#include <lt_help/lt.h>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();       
        vector<int> papers(size+1, 0);
        
        for(int ref : citations)
            papers[std::min(ref, size)]++;
        
        for(int i = size, sum = 0; i > 0; --i)
        {   sum += papers[i];
            if( i <= sum )
                return i;
        }
        return 0;
    }
};


void test(vector<int> citations)
{
    cout << "input: ";  
    outputVector(citations); 
    int r = Solution().hIndex(citations);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test({3,0,6,1,5});
}

// Result 
//
// 2022-11-19: Runtime 2ms 76.60% Memory 6.4MB 17.2%, https://leetcode.com/problems/h-index/submissions/847527789/
// 2023-07-29: Runtime 0ms 100% Memory 8.30MB 11.47%, https://leetcode.cn/problems/h-index/submissions/451261003/
