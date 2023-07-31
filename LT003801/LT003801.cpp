#include <lt_help/lt.h>

class Solution {
public:
    string countAndSay(int n) {
         vector<int> rst = {1};
         for(int i = 1; i < n; ++i)
         {  int val = 0, count = 0, size = rst.size();
            vector<int> rst2;
            for(int num : rst)
            {   if( num == val )
                    count++;
                else
                {   push_vec(rst2, count, val);
                    val   = num;
                    count = 1;
                }
            }
            push_vec(rst2, count, val);
            rst.swap(rst2);
         }
         
         string str;
         for(int val : rst )
             str.push_back( '0'+ val);

         return str;
    }
    
    void push_vec(vector<int>& vec, int count, int val){
        if( count <= 0 )
            return;
        if( count < 10 )
            vec.push_back(count);
        else
        {   static int stack[10];
            int len = 0;
            for(; count > 0; count /= 10 )
                stack[len++] = count % 10;
            for(int i = len-1; i >= 0; --i)
                vec.push_back(stack[i]);
        }
        vec.push_back(val);
    }
};



void test(int n)
{
    cout << "input: " << n << "; output=";
    string r = Solution().countAndSay(n);
    cout << r << ";" << endl;
}

int main(void)
{
    test(1);
    test(4);
}

// Result 
//
// 2022-11-16: Runtime 7ms 76.87% Memory 6.9MB 38.97%, https://leetcode.com/problems/count-and-say/submissions/844551294/
// 2023-02-17: Runtime 7ms 76.42% Memory 7MB 35.55%, https://leetcode.com/problems/count-and-say/submissions/899508875/
// 2023-07-31: Runtime 0ms 100.00% Memory 7.17MB 17.45%, https://leetcode.cn/problems/count-and-say/submissions/451862812/

