#include <lt_help/lt.h>

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if(node == NULL)
            return NULL;
        unordered_map<int,Node*> label_map;
        return cloneNode(label_map, node);
    }
    
    Node* cloneNode(unordered_map<int,Node*>& label_map, Node* node){
        auto iter = label_map.find(node->val);
        if( iter != label_map.end())
             return iter->second;
        
        Node* pnew = new Node(node->val);
        label_map[node->val] = pnew;
        for( auto neighbor : node->neighbors )
            pnew->neighbors.push_back(cloneNode(label_map, neighbor));
        
        return pnew;
    }
};



int main(void)
{   cout << "output: done!" << endl;
}


// Result 
//
// 2022-12-26: Runtime 3ms 96.93% Memory 8.9MB 34.89%, https://leetcode.com/problems/clone-graph/submissions/865514996/
// 2023-02-17: Runtime 7ms 68.50% Memory 8.7MB 74.82%, https://leetcode.com/problems/clone-graph/submissions/899792736/



