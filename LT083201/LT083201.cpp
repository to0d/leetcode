#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size(), column = image[0].size();
        for(int i = 0;i < row; ++i)
        {   vector<int>& line = image[i];
            for(int pos1 = 0, pos2 = column-1;  pos1 < pos2; ++pos1, --pos2)
            {   int v = line[pos2];
                line[pos2] = line[pos1];
                line[pos1] = v;
            }
            
            for(int j = 0; j < column; ++j)
                line[j] = 1 - line[j];
        }
        
        return image;
    }
};



void test(vector<vector<int>> image)
{
    cout << "input: ";
    outputVector(image);
    vector<vector<int>> r = Solution().flipAndInvertImage(image);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({{1,1,0},{1,0,1},{0,0,0}});
}


// Result 
//
// 2022-12-06: Runtime 7ms 44.79% Memory 8.8MB 47.5%, https://leetcode.com/problems/flipping-an-image/submissions/855591268/
// 2023-02-24: Runtime 5ms 66.59% Memory 8.8MB 47.67%, https://leetcode.com/problems/flipping-an-image/submissions/904194513/



