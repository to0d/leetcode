#include <lt_help/lt.h>

class Solution {

    //#define DBG
    #define BINARY_CAP 10000
    #define BINARY_LEN 4
    #define BINARY_FMT "%04d"
    
public:
    string multiply(string num1, string num2){
        if( num1.empty() || num1 == "0" || num2.empty() || num2 == "0" )
            return "0";
        if( num1.size() > num2.size() )
            return multiplyString(num2,num1);
        else 
            return multiplyString(num1,num2);
    }
    
private:

    string multiplyString(const string& num1, const string& num2){
        arr1.clear();
        arr2.clear();
        res.clear();

        bool positive1 = converFromString(num1, arr1), positive2 = converFromString(num2, arr2);

        for( int i = 0; i < (int)arr1.size(); ++i)
        {
            int v(0), j(0), k(i), a(arr1[i]);
            arr3.clear();
            
            // operator *
            for(; v > 0 || j < (int)arr2.size(); ++j, v /= BINARY_CAP)
            {   v += (j < (int)arr2.size()) ? a * arr2[j] : 0 ;
                arr3.push_back( v % BINARY_CAP);
            }
            
            // operator +
            v = 0;
            j = 0;
            for(; v > 0 || j < (int)arr3.size(); ++j, ++k, v /= BINARY_CAP)
            {
                v += ( j < (int)arr3.size()) ? arr3[j] : 0 ; 

                if( k < (int)res.size() )
                    v += res[k];
                else
                    res.push_back(0);

                res[k] = v % BINARY_CAP;
            }
        }
        
        return converToString(res, (positive1 == positive2));  
    }
 
    string converToString(vector<int>& array, bool positive){
        int len = array.size();
        char* buf = new char[ len * BINARY_LEN +2 ];
        char* pstr = buf;
        if( !positive )
            *pstr++ = '-';
        
        pstr += sprintf( pstr, "%d", array[--len]);
        for(; len > 0; --len )
            pstr += sprintf( pstr, BINARY_FMT, array[len-1]);
        
        *pstr = '\0';
        
        string r(buf);
        delete [] buf;
        return r;
    }
    
    bool converFromString(const string& num, vector<int>& array){
        const char* pstart = num.c_str(); 
        const char* pend = num.c_str() + num.size();
        char buf[ BINARY_LEN+1 ] = {0};
        int val;
        
        bool positive = true;
        if( *pstart == '-' )
        {   positive = false;
            ++pstart;
        }
        
        for( ; pstart <  pend; pend -= BINARY_LEN)
        {   if( pend >= ( pstart + BINARY_LEN ) )
                strncpy(buf, pend-BINARY_LEN, BINARY_LEN);
            else
            {   strncpy(buf, pstart, pend - pstart);
                buf[pend - pstart] = '\0';
            }
            
            sscanf(buf,"%d",&val);
            array.push_back(val);
        }
        
        return positive;
    }
    
    vector<int> arr1;
    vector<int> arr2; 
    vector<int> arr3;
    vector<int> res;
};



void test(string num1, string num2)
{
    cout << "input: num1=" << num1 << ", num2=" << num2;
    string r = Solution().multiply(num1, num2);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("123", "456");
}

// Result 
//
// 2022-11-16: Runtime 8ms 66.74% Memory 7MB 35.66%, https://leetcode.com/problems/multiply-strings/submissions/844574956/
// 2023-02-17: Runtime 4ms 89.90% Memory 6.9MB 35.56%, https://leetcode.com/problems/multiply-strings/submissions/899804673/



