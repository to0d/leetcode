#include <lt_help/lt.h>

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if( root == NULL || p == NULL || q == NULL)
            return NULL;
        if( p == q)
            return p;
        
        stack<TreeNode*> pPath, qPath;
        if( !findNodeInBST(pPath, p, root)|| !findNodeInBST(qPath, q, root))
            return NULL;

        // find common ancestor from root node
        TreeNode* pLast = root;
        while( !pPath.empty() && !qPath.empty() && pPath.top() == qPath.top() )
        {   pLast = pPath.top();
            pPath.pop();
            qPath.pop();
        }
        
        return pLast;
    }

    bool findNodeInBST( stack<TreeNode*>& path, TreeNode* pTarget, TreeNode* pNode){
        if( pNode == NULL )
             return false;

        if( pTarget == pNode 
         || pTarget->val < pNode->val && findNodeInBST(path, pTarget, pNode->left) 
         || pTarget->val > pNode->val && findNodeInBST(path, pTarget, pNode->right))
        {   path.push(pNode); 
            return true;
        }

        return false;
    } 
};



void test(TreeNode* root, TreeNode* p, TreeNode* q)
{
    cout << "input: root=";
    outputTree(root);
    cout << ", p=" << p->val << ", q=" << q->val;
    TreeNode* r = Solution().lowestCommonAncestor(root, p, q);
    cout << "; output: " ;
    if( r == NULL )
        cout << "null" ;
    else
        cout << r->val ;
    cout << ";" << endl;
}


int main(void)
{
    TreeNode* root = makeTree("{6,2,8,0,4,7,9,null,null,3,5}");
    test(root, findNode(root, 2), findNode(root, 8));
}

// Result 
//
// 2022-11-23: Runtime 36ms 44.6% Memory 23.4MB 27.57%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/848464723/
// 2023-02-20: Runtime 30ms 78.55% Memory 23.2MB 95.22%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/901587008/



