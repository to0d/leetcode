#include <lt_help/lt.h>




class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> rst;
        if( k == 0 )
        {   rst.push_back(target->val);
            return rst;
        }

        m_targetPath.clear();
        m_target = target;
        m_targetDepth = _findTarget(root);
        
        vector<TreeNode*> path;
        m_k = k;
        _visit(root, 0, path, rst, true, 0);
        return rst;
    }
    
    void _visit(TreeNode* node, int depth, vector<TreeNode*>& path, vector<int>& rst, bool inBranch, int commonDepth)
    {    
        path.push_back(node);
        
        if( inBranch )
        {   if( depth <= m_targetDepth && m_targetPath[depth] != node)
                inBranch = false;
            else
                commonDepth = depth;
        }
       
        if( inBranch )
        {   if( std::abs(depth - m_targetDepth) == m_k )
            {   rst.push_back(node->val);
                if( depth >= m_targetDepth )
                {   path.pop_back();
                    return;
                }
            }
        }
        else
        {
            if( (m_targetDepth + depth - 2*commonDepth) == m_k )
            {   rst.push_back(node->val);
                path.pop_back();
                return;
            }
        }
    
        if( node->left != NULL )
            _visit(node->left, depth+1, path, rst, inBranch, commonDepth);
        
        if( node->right != NULL )
            _visit(node->right, depth+1, path, rst, inBranch, commonDepth);
        
        path.pop_back();
    }
    
    int _findTarget(TreeNode* node)
    {   
        m_targetPath.push_back(node);
        if( node == m_target )
            return 0;
        if( node->left != NULL )
        {   int d = _findTarget(node->left);
            if( d != -1 )
                return d + 1;
        }
        if( node->right != NULL )
        {   int d = _findTarget(node->right);
            if( d != -1 )
                return d + 1;
        }
        m_targetPath.pop_back();
        return -1;
    
    }

    vector<TreeNode*> m_targetPath;
    TreeNode* m_target;
    int m_targetDepth;
    int m_k;
};



void test(TreeNode* root, TreeNode* target, int k)
{
    cout << "input: target=" << target->val << ", k=" << k << ", tree=";
    outputTree(root);
    vector<int> r = Solution().distanceK(root, target, k);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    TreeNode* root = makeTree("{3,5,1,6,2,0,8,null,null,7,4}");
    test(root, root->left, 2);
}

// Result 
//
// 2023-01-12: Runtime 6ms 70.62% Memory 12.6MB 84.3%, https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/876868515/


