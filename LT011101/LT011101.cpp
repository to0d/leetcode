#include <lt_help/lt.h>

class Solution {
public:

    int minDepth(TreeNode* root) {
        if( root == NULL)
            return 0;
        int minDepth = 65535;        
        searchDepth(root, minDepth, 1);
        return minDepth;
    }

    void searchDepth(TreeNode* node, int& minDepth, int depth){
        if(node == NULL || depth >= minDepth )
            return;

        if( node->left == NULL && node->right == NULL)
        {   minDepth = depth;
            return;
        }
        
        searchDepth(node->left, minDepth, depth + 1);
        searchDepth(node->right, minDepth, depth + 1);
    }
};


    
void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    int r = Solution().minDepth(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{3,9,20,null,null,15,7}"));
}

// Result 
//
// 2022-11-23: Runtime 437ms 12.40% Memory 144.6MB 80.90%, https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/848475633/
// 2023-02-22: Runtime 353ms 10.45% Memory 144.6MB 81.63%, https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/902625072/



