#include <lt_help/lt.h>

// **Pos-Order expression**  
//                                              _1
//   - Leaf node marked as #xx                 / \
//   - NULL child marked nothing              4   5
//                                           /
//   > For example: `#2,,4,#5,1,`           2
//
class Codec {
public:
    string serialize(TreeNode* root) {
        string output;
        if( root != NULL )
            makeSerialize(root, output); 
        return output;
    }

    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return NULL;
        
        stack<TreeNode*> s;
        const char *begin = data.c_str(), *end = begin + data.length();
        while (begin < end)
        {   if( *begin == '#' )
                s.push(createNode(++begin,end));
            else
            {   TreeNode* pnode = createNode(begin,end);
                if( pnode != NULL )
                {   pnode->right = s.top(); s.pop();
                    pnode->left = s.top();  s.pop();                 
                }
                s.push(pnode);
            }
        }
        return s.top();
    }
    
    void makeSerialize(TreeNode* node, string& output){
        if( node->left == NULL && node->right == NULL )
            output += "#";
        else
        {   if( node->left != NULL )
                makeSerialize(node->left, output);
            else
                output += ",";   

            if( node->right != NULL )
                makeSerialize(node->right, output);
            else
                output += ",";
        }
        output += to_string(node->val);
        output += ",";
    }
    
    TreeNode* createNode(const char* &begin, const char* end) {
        const char* pos = begin;
        while( *begin != ',' && begin < end)
            ++begin;
        ++begin;
        int val;
        if( pos == begin || sscanf(pos,"%d",&val) != 1)
            return NULL;
        return new TreeNode(val);
    }
};



void test(TreeNode* root)
{
    cout << "input: ";
    outputTree(root);
    string r = Codec().serialize(root);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(makeTree("{1,2,3,null,null,4,5}"));
}

// Result 
//
// 2022-11-23: Runtime 98ms 24.77% Memory 28.1MB 99.7%, https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/848459349/
// 2023-02-20: Runtime 41ms 95.4% Memory 28.2MB 99.4%, https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/901585303/



