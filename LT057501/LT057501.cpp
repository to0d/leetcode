#include <lt_help/lt.h>

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::sort(candyType.begin(), candyType.end());
        int last = -1, typeCount = 0;
        for(auto v : candyType)
            if( v != last )
            {   typeCount++;
                last = v;
            }
        
        return typeCount < (candyType.size() / 2) ? typeCount : (candyType.size() / 2);
    }
};



void test(vector<int> candyType)
{
    cout << "input: ";
    outputVector(candyType);
    int r = Solution().distributeCandies(candyType);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({1,1,2,2,3,3});
}


// Result 
//
// 2022-12-02: Runtime 411ms 17.50% Memory 81.7MB 91.47%, https://leetcode.com/problems/distribute-candies/submissions/853406613/
// 2023-02-24: Runtime 196ms 97.21% Memory 81.7MB 97.39%, https://leetcode.com/problems/distribute-candies/submissions/904175191/




