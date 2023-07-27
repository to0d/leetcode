#include <lt_help/lt.h>

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size(), pos = 0;
        if( len == 0 )
             return "";

        bool abs_path = false;
        if( path[0] == '/' )
        {   abs_path = true;
            pos++;
        }
        
        deque<string> path_names;  string name; char c;
        for(; pos <= len ; ++pos)
        {   if( pos == len || (c = path[pos]) == '/' )
            {   if( !name.empty() )
                {   if( name == ".." )
                    {   if( !path_names.empty())
                            path_names.pop_back();
                    }
                    else if( name != "." )
                        path_names.push_back(name);
                    name.clear();
                }
            }
            else
                name.push_back(c);
        }

        string rst = abs_path ? "/" : ""; int idx = 0;
        for(auto n : path_names )
        {   if(idx++ != 0)
                 rst.push_back('/');
            rst += n;
        }

        return rst;
    }
};



void test(string path)
{
    cout << "input: " << path << "; output: "; 
    string r = Solution().simplifyPath(path);
    cout << r << ";" << endl;
}

int main(void)
{
    test("/home/");
    test("/../");
    test("/home//foo/");
}

// Result 
//
// 2022-11-19: Runtime 7ms 62.69% Memory 7.5MB 91.51%, https://leetcode.com/problems/simplify-path/submissions/846153298/
// 2023-02-18: Runtime 4ms 83.40% Memory 7.5MB 93.85%, https://leetcode.com/problems/simplify-path/submissions/900092020/
// 2023-07-27: Runtime 4ms 89.09% Memory 7.05MB 93.73%, https://leetcode.cn/problems/simplify-path/submissions/450751761/



