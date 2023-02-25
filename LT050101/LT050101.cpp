#include <lt_help/lt.h>



class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        m_path.clear();
        _move(root);
        vector<int> modeArr;
        int modeCount = 0, lastCount = 1, lastVal = next();
        while(hasNext())
        {   int val = next();
            if( val == lastVal )
            {   ++lastCount; 
            }
            else
            {   if( lastCount > modeCount )
                {   modeArr.clear();
                    modeArr.push_back(lastVal);
                    modeCount = lastCount;
                }
                else if ( lastCount == modeCount )
                {   modeArr.push_back(lastVal);
                }
                lastCount = 1;
                lastVal = val;
            }
        }

        if( lastCount > modeCount )
        {   modeArr.clear();
            modeArr.push_back(lastVal);
            modeCount = lastCount;
        }
        else if ( lastCount == modeCount )
        {   modeArr.push_back(lastVal);
        }
        return modeArr;
    }
    
    int next() {
        TreeNode* node = m_path.back();
        m_path.pop_back();
        int val = node->val;
        _move(node->right);
        return val;
    }       

    bool hasNext() {
        return m_path.size() != 0;
    }
    
    void _move(TreeNode* node)
    {   while( node != NULL )
        {   m_path.push_back(node);
            if( node->left != NULL )
                node = node->left;
            else
                node = NULL;
        }
    }
    
    vector<TreeNode*> m_path;
};

void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<int> r = Solution().findMode(root);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(makeTree("{1,null,2,2}"));
}


// Result 
//
// 2023-01-09: Runtime 19ms 86.6% Memory 24MB 84.88%, https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/874802106/

