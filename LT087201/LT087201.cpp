#include <lt_help/lt.h>



class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> path1 = {root1};
        vector<TreeNode*> path2 = {root2};
        bool forward1 = true, forward2=  true;
        while(_nextLeaf(path1, forward1))
        {   //cout << "L1="; for( auto n : path1 ) cout << " " << n->val; cout << endl;
            if(!_nextLeaf(path2, forward2))
                return false;
            //cout << "L2="; for( auto n : path2 ) cout << " " << n->val; cout << endl;
            if(path1[path1.size()-1]->val != path2[path2.size()-1]->val)
                return false;
            forward1 = false;
            forward2 = false;
        }

        return !_nextLeaf(path2, forward2);
    }
    
    bool _nextLeaf(vector<TreeNode*>& paths, bool forward)
    {
        while(paths.size() > 0)
        {   TreeNode* node = paths[paths.size()-1];
            if( forward )
            {   //cout << "forward=" << node->val << endl;
                if(node->left != NULL)
                    paths.push_back(node->left);
                else if( node->right != NULL)
                    paths.push_back(node->right);
                else
                    return true;
            }
            else
            {   if( paths.size() == 1 )
                    return false;
                TreeNode* parent = paths[paths.size()-2];
                if( parent->left == node && parent->right != NULL )
                {   paths[paths.size()-1] = parent->right;
                    forward = true;
                }
                else
                    paths.pop_back();
            }
        }

        return false;
    }
};

void test(TreeNode* root1, TreeNode* root2)
{
    cout << "input: tree1=";
    outputTree(root1);
    cout << ", tree2=";
    outputTree(root2);
    bool r = Solution().leafSimilar(root1, root2);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeTree("{3,5,1,6,2,9,8,null,null,7,4}"), makeTree("{3,5,1,6,7,4,2,null,null,null,null,null,null,9,8}"));
}


// Result 
//
// 2022-12-04: Runtime 3ms 79.32% Memory 12.6MB 99.95%, https://leetcode.com/problems/leaf-similar-trees/submissions/854361757/


