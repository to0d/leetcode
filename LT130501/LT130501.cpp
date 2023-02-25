#include <lt_help/lt.h>



class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        _move(root);
    }
    
    int next() {
        TreeNode* node = m_path.back();
        m_path.pop_back();
        int val = node->val;
        _move(node->right);
        return val;
    }
    
    int peek()
    {   return m_path.back()->val;
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

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> rst;
        BSTIterator it1(root1), it2(root2);
        while( it1.hasNext() && it2.hasNext() )
        {   int val1 = it1.peek(), val2 = it2.peek();
            if( val1 < val2 )
            {   rst.push_back(val1);
                it1.next();
            }
            else
            {   rst.push_back(val2);
                it2.next();
            }
        }
        
        while( it1.hasNext() )
            rst.push_back(it1.next());
        
        while( it2.hasNext() )
            rst.push_back(it2.next());
        
        return rst;
    }
};


void test(TreeNode* root1, TreeNode* root2)
{
    cout << "input: t1=";
    outputTree(root1);
    cout << ", t2=";
    outputTree(root2);
    vector<int> r = Solution().getAllElements(root1, root2);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test(makeTree("{2,1,4}"), makeTree("{1,0,3}"));
}

// Result 
//
// 2023-01-14: Runtime 167ms 54.38% Memory 84.4MB 78.61%, https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/877771712/


