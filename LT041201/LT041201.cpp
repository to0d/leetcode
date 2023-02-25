#include <lt_help/lt.h>



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> rst;
        
        for( int i = 1; i <= n; ++i )
        {
            string str;
            
            if( i % 3 == 0 )
            {   str += "Fizz";
            }
            
            if( i % 5 == 0 )
            {   str += "Buzz";
            }
             
            if( str.length() == 0 )
            {   str += std::to_string(i);
            }
            
            rst.push_back(str);
        }   

        return rst;
    }
};
    


void test(int n)
{
    cout << "input: " << n;
    vector<string> r = Solution().fizzBuzz(n); 
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(3);
}

// Result 
//
// 2022-11-22: Runtime 4ms 53.36% Memory 8MB 41.32%, https://leetcode.com/problems/fizz-buzz/submissions/847781340/

