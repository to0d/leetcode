#include <lt_help/lt.h>

class Solution {
public:
    string getHint(string secret, string guess){
        int bull(0), cows(0), len(secret.size());
        int secHeap [10] = {0}, gueHeap [10] = {0};  

        for(int i = 0;i < len ; ++i)
        {   char s = secret[i], g = guess[i];
            if( s == g)
                ++bull;
            else
            {   secHeap[ (int)(s - '0') ]++; 
               gueHeap[ (int)(g - '0') ]++; 
            }
        }
        
        for(int i = 0; i < 10 ; ++i)
            cows += min(secHeap[i], gueHeap[i]);

        return to_string(bull) + "A" + to_string(cows) + "B";
    }
};



void test(string secret, string guess)
{
    cout << "input: secret=" << secret << ", guess=" << guess;
    string r = Solution().getHint(secret, guess);
    cout << "; output: " << r << endl;
}


int main(void)
{
    test("1807", "7810");
}

// Result 
//
// 2022-11-19: Runtime 8ms 37.88% Memory 6.5MB 96.55%, https://leetcode.com/problems/bulls-and-cows/submissions/846344614/
// 2023-02-22: Runtime 3ms 86.76% Memory 6.5MB 96.41%, https://leetcode.com/problems/bulls-and-cows/submissions/902736248/



