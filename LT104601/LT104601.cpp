#include <lt_help/lt.h>



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        for(; size > 1; --size)
        {   for(int i = 0;i < 2; ++i)
            {   for(int j = 1; j < (size-i); ++j)
                {   if(stones[j] < stones[j-1])
                    {   int v = stones[j-1];
                        stones[j-1] = stones[j];
                        stones[j] = v;
                    }
                }                    
            }
            stones[size-2] = std::abs(stones[size-1]-stones[size-2]);
        }
        return stones[0];
    }
};



void test(vector<int> stones)
{
    cout << "input: ";
    outputVector(stones);
    int r = Solution().lastStoneWeight(stones);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({2,7,4,1,8,1});
}


// Result 
//
// 2022-12-08: Runtime 2ms 53.79% Memory 7.6MB 83.8%, https://leetcode.com/problems/last-stone-weight/submissions/856480056/



