#include <lt_help/lt.h>

struct TNode
{   TreeNode* node;
    int deep;
};

bool compare_tnode(const TNode& a, const TNode& b)
{   return a.node->val < b.node->val;
}

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> rst;
        vector<TNode> nodes;
        _find(root, nodes);
        std::sort(nodes.begin(), nodes.end(), compare_tnode);
        
        int size = nodes.size();
        unordered_set<TreeNode*> used;
        for(int i = 0;i < size-1; ++i)
        {   TNode& a = nodes[i];
            if( used.count(a.node) != 0 )
                continue;
            
            int find = 0;
            for(int j = i+1; j < size; ++j)
            {   TNode& b = nodes[j];
                if( b.node->val != a.node->val)
                    break;
                if( used.count(b.node) != 0 || b.deep != a.deep)
                    continue;
                if( _isEqual(a.node, b.node) )
                {   find++;
                    used.insert(b.node);
                }
            }

            if( find > 0 )
            {   rst.push_back(a.node);
                used.insert(a.node);
            }
        }

        return rst;
    }
    
    bool _isEqual(TreeNode* a, TreeNode* b){  
        if( a == NULL )
            return b == NULL;
        if( b == NULL )
            return false;
        if( a->val != b->val )
            return false;
        return _isEqual(a->left, b->left) && _isEqual(a->right, b->right);
    }
    
    int _find(TreeNode* node, vector<TNode>& nodes) {   
        if( node->left == NULL && node->right == NULL)
        {   TNode tn;
            tn.node = node;
            tn.deep = 1;
            nodes.push_back(tn);
            return 1;
        }
        
        int leftDeep = 0, rightDeep = 0;
        if( node->left != NULL )
            leftDeep = _find(node->left, nodes);
        if( node->right != NULL )
            rightDeep = _find(node->right, nodes);
        
        int deep = std::max(leftDeep, rightDeep) + 1;
        TNode tn;
        tn.node = node;
        tn.deep = deep;
        nodes.push_back(tn);
        return deep;
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    vector<TreeNode*> r = Solution().findDuplicateSubtrees(root);
    cout << "; output: [";
	int i = 0;
	for( TreeNode* n : r )
    {	if( i != 0)
            std::cout << ", ";
		outputTree(n);
	}
	cout << "];" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,4,null,2,4,null,null,4}"));
}

// Result 
//
// 2023-01-08: Runtime 54ms 19.14% Memory 21.7MB 99.64%, https://leetcode.com/problems/find-duplicate-subtrees/submissions/874118100/
// 2023-02-25: Runtime 50ms 20.84% Memory 21.6MB 99.66%, https://leetcode.com/problems/find-duplicate-subtrees/submissions/904434723/


