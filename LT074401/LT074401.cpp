#include <lt_help/lt.h>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        if( letters[0] > target || letters[size-1] <= target) 
            return letters[0];

        int low = 0, high = size - 1;
        while(low >=0 && low <= high )
        {   int m = ( high + low ) / 2;
            char v = letters[m] ;
            if( v > target )
                high = m - 1;
            else if( v < target )
                low = m + 1;
            else
            {   for(int i = m + 1; i < size; ++i )
                    if( letters[i] > target )
                        return letters[i];
                break;
            }
        }

        return letters[high+1];
    }
};



void test(vector<char> letters, char target)
{
    cout << "input: target=" << target << ", letters=";
    outputVector(letters);
    char r = Solution().nextGreatestLetter(letters, target);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({'c','f','j'}, 'a');
}


// Result 
//
// 2022-12-02: Runtime 49ms 5.20% Memory 16MB 52.17%, https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/853438859/
// 2023-02-24: Runtime 14ms 80.34% Memory 15.9MB 81.22%, https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/904190838/



