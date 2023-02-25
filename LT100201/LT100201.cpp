#include <lt_help/lt.h>



class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int buf1[26], buf2[26], count1, size = words.size();
        count1 = _count(words[0], buf1);
        for(int i = 1 ; count1 > 0 && i < size; ++i)
        {   _count(words[i], buf2);
            // for(int k = 0; k < 26; ++k) if(buf1[k] > 0) cout << " " << (char)('a'+k) << "=" << buf1[k]; cout << endl;
            for(int j = 0; j < 26; ++j )            
                if( buf1[j] != 0 )
                    if( buf2[j] != 0)
                        buf1[j] = std::min(buf1[j], buf2[j]);
                    else 
                    {   buf1[j] = 0;
                        --count1;
                    }
        }
        vector<string> rst;
        char b[1];
        for(int i = 0 ; count1 > 0 && i < 26; ++i)
            if( buf1[i] != 0 )
            {   b[0] = (char)('a' + i);
                string t(b, 1);
                for( int j = 0; j < buf1[i]; ++j)
                    rst.push_back(t);
                --count1;
            }
        return rst;
    }
    static int _count(string s, int* buf)
    {   int len = s.length(), count = 0;
        memset(buf, 0, sizeof(int)*26);
        for(int i = 0; i < len; ++i)
            if(buf[s.at(i)-'a']++ == 0)
                ++count;
        //cout << "_count: s=" << s; for(int i = 0;i < 26; ++i) if(buf[i] > 0) cout << " " << (char)('a'+i) << "=" << buf[i]; cout << endl;
        return count;
    }
};


void test(vector<string> words)
{
    cout << "input: ";
    outputVector(words);
    vector<string> r = Solution().commonChars(words);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({"bella","label","roller"});
}


// Result 
//
// 2022-12-07: Runtime 8ms 78.45% Memory 9.3MB 74.80%, https://leetcode.com/problems/find-common-characters/submissions/855899239/



