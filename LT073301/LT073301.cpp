#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int column = image[0].size();
        int target = image[sr][sc];
        if( target == color )
            return image;
        
        stack<int> rstack, cstack;
        rstack.push(sr);
        cstack.push(sc);        
        while(!rstack.empty())
        {   int r = rstack.top();
            int c = cstack.top();
            rstack.pop();
            cstack.pop();
            if( image[r][c] != target )
                continue;
            image[r][c] = color;
            if( r > 0 )
            {   rstack.push(r-1);
                cstack.push(c);
            }
            if( (r+1) < row )
            {   rstack.push(r+1);
                cstack.push(c);
            }
            if( c > 0 )
            {   rstack.push(r);
                cstack.push(c-1);
            }
            if( (c+1) < column )
            {   rstack.push(r);
                cstack.push(c+1);
            }
        }
        return image;
    }
};


void test(vector<vector<int>> image, int sr, int sc, int color)
{
    cout << "input: sr=" << sr << ", sc=" << sc << ", color=" << color << ", image=";
    outputVector(image);
    vector<vector<int>> r = Solution().floodFill(image, sr, sc, color);
    cout << "; output: ";
    outputVector(r);
    cout  << ";" << endl;
}

int main(void)
{   test({{1,1,1},{1,1,0},{1,0,1}},1,1,2);
}


// Result 
//
// 2022-12-06: Runtime 8ms 74.57% Memory 14.4MB 17.41%, https://leetcode.com/problems/flood-fill/submissions/855581793/



