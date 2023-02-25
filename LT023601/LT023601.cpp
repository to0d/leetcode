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

        if( !findNodeInBinaryTree(pPath, p, root)
         || !findNodeInBinaryTree(qPath, q, root))
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

    bool findNodeInBinaryTree( stack<TreeNode*>& path, TreeNode* pTarget, TreeNode* pNode) {
        if( pNode == NULL )
            return false;

        if( pTarget == pNode 
         || findNodeInBinaryTree(path, pTarget, pNode->left) 
         || findNodeInBinaryTree(path, pTarget, pNode->right))
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
    TreeNode* tree = makeTree("{3,5,1,6,2,0,8,null,null,7,4}");
    test(tree, findNode(tree, 5), findNode(tree, 1));
}

// Result 
//
// 2022-11-23: Runtime 34ms 14.43% Memory 16.8MB 13.45%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/848485979/
// 2023-02-22: Runtime 29ms 14.15% Memory 16.6MB 13.89%, https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/902723471/


