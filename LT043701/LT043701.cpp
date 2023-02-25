#include <lt_help/lt.h>



class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if( root == NULL )
            return 0;
        m_count = 0;
        m_targetSum = targetSum;
        m_set.clear();
        _pathSum(root, targetSum, 0);
        return m_count;
    }
    
    void _pathSum(TreeNode* node, long target, int len) {
        if( len == 0 )
        {   if( m_set.count(node) != 0 )
                return;
            m_set.insert(node);
        }
        //cout << "node=" << node->val << ", target=" << target << ", len=" << len << endl;
        if( node->val == target)
        {   //cout << "node->val == target" << endl;
            m_count++;
        }
        
        if(node->left != NULL)
            _pathSum(node->left, target - node->val, len+1);
        
        if(node->right != NULL)
            _pathSum(node->right, target - node->val, len+1);
                
        if( len > 0 )
            _pathSum(node, m_targetSum, 0);
    }
    
    int m_count;
    long m_targetSum;
    unordered_set<TreeNode*> m_set;
};



    
void test(TreeNode* root, int targetSum)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().pathSum(root, targetSum);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{10,5,-3,3,2,null,11,3,-2,null,1}"), 8);
}

// Result 
//
// 2023-01-07: Runtime 166ms 7.11% Memory 19.3MB 37.17%, https://leetcode.com/problems/path-sum-iii/submissions/873075421/

