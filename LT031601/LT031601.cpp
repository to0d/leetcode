#include <lt_help/lt.h>



// struct DupNode 
// {
//     int childNodeIndex[26];
//     int maxDepth;
//     DupNode() : maxDepth(1) { memset(childNodeIndex, 0, sizeof(childNodeIndex)); }
// };
// 
// struct DupTree
// {
//     vector<DupNode> nodeArray;
//     DupNode  rootNode;
//     DupNode* nodePath[27];
//     
// #define INDEX_LEAF 1
// #define INDEX_NULL 0
// 
//     DupTree()
//     {
//         nodeArray.push_back(DupNode()); // 0: null
//         nodeArray.push_back(DupNode()); // 1: leaf node, not expand
//     }
//     
// public:
// 
//     void addLetter(char c)
//     {
//         addLetter(rootNode, c - 'a', nodePath, 0);
//     }
//     
//     void addLetter(DupNode& node, int c, DupNode** nodePath, int level)
//     {
//         //cout << "addletter, c= " << c << endl;
//         nodePath[level] = &node;
//         
//         for(int i = 0; i < 26; ++i )
//         {
//             int& index = node.childNodeIndex[i];
//             if( index == INDEX_NULL )
//             {
//                 if( i == c )
//                 {
//                     index = INDEX_LEAF;
//                     updateMaxDepth(nodePath, level, 2);
//                 }
//             }
//             else if( i != c )
//             {
//                 if( index == INDEX_LEAF )
//                 {
//                     nodeArray.push_back(DupNode());
//                     index = nodeArray.size() - 1;
//                 }
//                 
//                 addLetter(nodeArray[index], c, nodePath, level+1 );
//             }
//         }
//     }
//     
//     void updateMaxDepth( DupNode** nodePath, int level, int maxDepth )
//     {
//         //cout << "updateMaxDepth, level = " << level << ", depth=" << maxDepth << endl; 
//         
//         DupNode& node = (*nodePath)[level];
//         if( level >=0 && node.maxDepth < maxDepth )
//         {
//             node.maxDepth = maxDepth;
//             updateMaxDepth(nodePath, level-1, maxDepth+1 );
//         }
//         //else
//         //    cout << "updateMaxDepth return" << endl;
//     }
//     
//     string findMinString()
//     {
//         string res;   
//         DupNode* node = &rootNode;
//         int length = rootNode.maxDepth - 1;
//         while( length > 0)
//         {
//             bool findMinChild = false;
//             
//             for( int i = 0; !findMinChild && i < 26; ++i)
//             {
//                 int childIndex = (*node).childNodeIndex[i];
//                 if( childIndex == INDEX_NULL )
//                     continue;
//                 
//                 int childLength = 1;
//                 DupNode* childNode = NULL;
//                 if( childIndex != INDEX_LEAF )
//                 {
//                     childNode = &(nodeArray[childIndex]);
//                     childLength = (*childNode).maxDepth;
//                 }
//                 
//                 if( childLength == length)
//                 {
//                     node = childNode;
//                     findMinChild = true;
//                     res.push_back('a'+i);
//                 }
//             }
//             
//             if( !findMinChild)
//                 break;
//             
//             --length;
//         }
//         
//         return res;
//     }
//     
//     void printNode(DupNode& node)
//     {
//         //cout << "MaxDepth=" << node.maxDepth;
//         for( int i = 0 ; i < 26; ++i)
//             cout << ", " << node.childNodeIndex[i];
//         //cout << endl;
//     }
//     
//     void print()
//     {
//         //cout << "Root: ";
//         printNode(rootNode);
//         for( int i = 0; i < nodeArray.size(); ++i)
//         {
//             //cout << i << " :";
//             printNode(nodeArray[i]);
//         } 
//     }
// };
// 
// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         
//         DupTree dupTree;
//         char last = 0;
//         for( char c : s)
//         {
//             if( c == last )
//                 continue;
//             
//             dupTree.addLetter(c);
//             last = c;
//         }
//         
//         dupTree.print();
//         return dupTree.findMinString();
//     }
// };
// 
// 
struct DupNode 
{
    int childNodeIndex[26];
    int maxDepth;
    DupNode() : maxDepth(1)
    { 
        for( int i = 0; i < 26; ++i)
            childNodeIndex[i] = 0;
    }
    
    DupNode(const DupNode& o) 
    {
        maxDepth = o.maxDepth;
        for( int i = 0; i < 26; ++i)
            childNodeIndex[i] = o.childNodeIndex[i];
    }
};

struct DupTree
{
    vector<DupNode> nodeArray;
    DupNode  rootNode;
    DupNode* nodePath[30];
    
#define INDEX_LEAF 1
#define INDEX_NULL 0

    DupTree()
    {
        nodeArray.push_back(DupNode()); // 0: null
        nodeArray.push_back(DupNode()); // 1: leaf node, not expand
    }
    
public:

    void addLetter(char c)
    {
        addLetter(&rootNode, c - 'a', nodePath, 0);
    }
    
    void addLetter(DupNode* node, int c, DupNode** nodePath, int level)
    {
        //cout << "addletter, c= " << c << ",level=" << level <<  endl;
        
        nodePath[level] = node;
        printNode(*node);
        
        for(int i = 0; i < 26; ++i )
        {
            if( i == c )
            {
                if( node->childNodeIndex[i] == INDEX_NULL )
                {
                    node->childNodeIndex[i] = INDEX_LEAF;
                    updateMaxDepth(nodePath, level, 2);
                }
                continue;
            }
            
            if( node->childNodeIndex[i] == INDEX_LEAF )
            {
                nodeArray.push_back(DupNode());
                node->childNodeIndex[i] = nodeArray.size() - 1;            
            } 
            
            if( node->childNodeIndex[i] > INDEX_LEAF 
             && node->childNodeIndex[i] < (int)nodeArray.size() )
            {
                DupNode* node2 = &(nodeArray[node->childNodeIndex[i]]);
                addLetter(node2, c, nodePath, level + 1 );
            }
        }
    }
    
    void updateMaxDepth( DupNode** nodePath, int level, int maxDepth )
    {
        if( level < 0 )
            return ;
        
        DupNode* node = nodePath[level];
       // cout << "updateMaxDepth, level = " << level << ", depth=" << maxDepth 
       //      << "node.max " << node->maxDepth << endl; 
       //  printNode(*node);
        
        if(node->maxDepth < maxDepth )
        {
            node->maxDepth = maxDepth;
            updateMaxDepth(nodePath, level-1, maxDepth+1 );
        }
        //else
        //    cout << "updateMaxDepth return" << endl;
    }
    
    string findMinString()
    {
        string res;   
        DupNode* node = &rootNode;
        int length = rootNode.maxDepth - 1;
        while( length > 0)
        {
            bool findMinChild = false;
            
            for( int i = 0; !findMinChild && i < 26; ++i)
            {
                int childIndex = (*node).childNodeIndex[i];
                if( childIndex == INDEX_NULL )
                    continue;
                
                int childLength = 1;
                DupNode* childNode = NULL;
                if( childIndex != INDEX_LEAF )
                {
                    childNode = &(nodeArray[childIndex]);
                    childLength = (*childNode).maxDepth;
                }
                
                if( childLength == length)
                {
                    node = childNode;
                    findMinChild = true;
                    res.push_back('a'+i);
                }
            }
            
            if( !findMinChild)
                break;
            
            --length;
        }
        
        return res;
    }
    
    void printNode(DupNode& node)
    {
        //cout << "MaxDepth=" << node.maxDepth;
        for( int i = 0 ; i < 26; ++i)
            cout << ", " << node.childNodeIndex[i];
        //cout << endl;
    }
    
    void print()
    {
        //cout << "Root: ";
        printNode(rootNode);
        for( size_t i = 0; i < nodeArray.size(); ++i)
        {
            cout << i << " :";
            printNode(nodeArray[i]);
        } 
    }
};


class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        DupTree dupTree;
        char last = 0;
        
        for( size_t i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if( c == last )
                continue;
            
            dupTree.addLetter(c);
            last = c;
        }
        
        // dupTree.print();
        return dupTree.findMinString();
    }
};

     
// void test(vector<int>& nums1, vector<int>& nums2)
// {
//     cout << "input: nums1=";
//     outputVector(nums1);
//     cout << ", nums2=";
//     outputVector(nums2);
//     vector<int> r = Solution().intersect(nums1, nums2);
//     cout << "; output: "; 
//     outputVector(r);
//     cout << endl;
// }


int main(void)
{
    cout << "output: error" << endl;
}

// Result 
//
// 2022/11/21
//     Runtime Error
