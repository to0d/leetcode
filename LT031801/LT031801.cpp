#include <lt_help/lt.h>



class Solution {
public:
    int maxProduct(vector<string>& words) {
        
       int len = words.size();
       if( len == 0 ) 
           return 0;
        
       int(*array)[26] = new int[len][26];
       
       for( int i = 0; i < len ; ++i )
       {
           int* pc = array[i];
           for(int j = 0 ; j < 26 ;++j )
               pc[j] = 0;
           
           for( char c : words.at(i))
               pc[c-'a']++;
       }
       
       int res = -1;
       for( int i = 0; i < len ; ++i )
       {
           int la = words[i].size();
           
           for( int j = i+1; j < len ; ++j )
           {
               int lb = words[j].size();
               if( la*lb > res)
               {
                   bool hasCommon = false;
                   for(int k=0; !hasCommon && k < 26 ;++k )
                       if( array[i][k] > 0 && array[j][k] > 0)
                           hasCommon = true;
                       
                   if( !hasCommon )
                       res = la * lb;                  
               }
           }      
       }
       
       delete array;  
       return res < 0 ? 0 : res;
    }
};


void test(vector<string> words)
{
    cout << "input: ";
    outputVector(words);
    cout << "; output: "; 
    int r = Solution().maxProduct(words);
    cout << r << ";" << endl;
}

int main(void)
{
    test({"abcw","baz","foo","bar","xtfn","abcdef"});
}

// Result 
//
// 2022-11-18: Runtime 103ms 55.86% Memory 25.4MB 23.88%, https://leetcode.com/problems/maximum-product-of-word-lengths/submissions/845863691/

