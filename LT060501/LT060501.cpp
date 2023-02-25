#include <lt_help/lt.h>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 10[0010000111]01
        //    flowerbed
        // 0,1,2 --> 0
        // 3,4   --> 1    10001     -> can plant 1
        // 5,6   --> 2    10000001  -> can plant 2
        int size = flowerbed.size();
        int last = -2;
        for(int i = 0; n > 0 && i < size; ++i)
            if(flowerbed[i] == 1)
            {   n -= canPlant(i - last - 1);
                last = i;
            }

        if( n > 0 )
            n -= canPlant(size - last);
        
        return n <= 0;
    }

    int canPlant(int space){   
        return space <= 2 ? 0 : (space-1)/2;
    }
};



void test(vector<int> flowerbed, int n)
{
    cout << "input: n=" << n << ", flowerbed=";
    outputVector(flowerbed);
    bool r = Solution().canPlaceFlowers(flowerbed, n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,0,0,0,1}, 1);
}


// Result 
//
// 2022-11-30: Runtime 41ms 11.11% Memory 20.1MB 99.77%, https://leetcode.com/problems/can-place-flowers/submissions/852366704/
// 2023-02-24: Runtime 3ms 100% Memory 20.2MB 92.9%, https://leetcode.com/problems/can-place-flowers/submissions/904180226/



