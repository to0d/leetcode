#include <lt_help/lt.h>




// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
//#define DBG(x) x
#define DBG(x)
public:
    Node* connect(Node* root) {
        queue<Node*> nodeQueue;
		nodeQueue.push(root);
		nodeQueue.push(NULL);
		Node* last = NULL;
		bool findBottom = false;
		while( !nodeQueue.empty())
		{	Node* top = nodeQueue.front();
			nodeQueue.pop();
			DBG(cout << "pop: "; if (top == NULL) cout << "NULL" ; else cout << top->val; cout << endl;)
			if( last != NULL )
				last->next = top;
			if( top == NULL )
			{	if( last == NULL )
					break;
				nodeQueue.push(NULL);
				DBG(cout << "push: NULL" << endl;)
			}
			else
			{	if( top->left != NULL)
				{	nodeQueue.push(top->left);
					DBG(cout << "push: " << top->left->val << ", "<< top->right->val << endl;)
				}
				if( top->right != NULL)
				{	nodeQueue.push(top->right);
					DBG(cout << "push: " << top->left->val << ", "<< top->right->val << endl;)
				}
			}

			last = top;
		}
		return root;
    }
};


int main(void)
{
    cout << "output: done!;" << endl;
}

// Result 
//
// 2022-12-30: Runtime 17ms 48.59% Memory 17.6MB 27.88%, https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/867828199/


