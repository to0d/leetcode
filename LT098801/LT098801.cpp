#include <lt_help/lt.h>



class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        m_smallestPaths.clear();
        vector<int> path;
        _smallestFromLeaf(root, path, 0);
        static char buf[8500];
        int buf_len = 0, pos = m_smallestPaths.size()-1;
        for(; pos >= 0 ; --pos)
            buf[buf_len++] = 'a' + m_smallestPaths[pos];
        return string(buf, buf_len);
    }
    
    void _smallestFromLeaf(TreeNode* node, vector<int>& path, int len) {
        
        if( path.size() == len )
            path.push_back(node->val);
        else
            path[len] = node->val;
        
        len++;
        
        if( node->left == NULL && node->right == NULL )
        {   //cout << "path:"; std::copy(path.begin(), path.begin()+len, std::ostream_iterator<int>(std::cout, " ")); cout << endl;
            if( m_smallestPaths.size() != 0 )
            {   int pos1 = m_smallestPaths.size()-1, pos2 = len-1;
                for(; pos1 >= 0 && pos2 >= 0; --pos1, --pos2)
                {   if( m_smallestPaths[pos1] < path[pos2] )
                        return;
                    else if( m_smallestPaths[pos1] > path[pos2] )
                        break;
                }
                if( pos1 < 0 && pos2 >= 0 )
                    return;
            }
            //cout << "update" << endl;
            m_smallestPaths.clear();
            std::copy(path.begin(), path.begin()+len, std::back_inserter(m_smallestPaths));
            return;
        }
        
        if ( node->left != NULL )
            _smallestFromLeaf(node->left, path, len);
        
        if ( node->right != NULL )
            _smallestFromLeaf(node->right, path, len);
    }
    
    vector<int> m_smallestPaths;
};

void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);   
    string r = Solution().smallestFromLeaf(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{0,1,2,3,4,3,4}"));
}

// Result 
//
// 2023-01-31: Runtime 13ms 61.7% Memory 19.6MB 56.64%, https://leetcode.com/problems/smallest-string-starting-from-leaf/submissions/888695168/

