#include <lt_help/lt.h>



class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> rst;
        while( label > 0 )
        {   rst.push_back(label);
            int parent = (label%2 == 0) ? label/2 : (label-1)/2;
            int level = _bigLenOf(parent);
            int begin = pow(2, level-1);
            int end   = pow(2, level) - 1;
            label = end - (parent - begin);
        }
        
        std::reverse(rst.begin(), rst.end());
        return rst;
    }
    
    int _bigLenOf(int val)
    {   int len = 0;
        for(; val > 0; val = val >> 1)
            ++len;
        return len;
    }
};


void test(int label)
{
    cout << "input: " << label;
    vector<int> r = Solution().pathInZigZagTree(label);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(14);
}

// Result 
//
// 2023-01-13: Runtime 0ms 100% Memory 6.3MB 67.74%, https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/submissions/877489853/


