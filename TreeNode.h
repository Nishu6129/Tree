#include <vector>
using namespace std;

template < typename T>
class TreeNode{
    public:
    T data;

    // vector< TreeNode<T> *> children;  we can do this as well

    vector < TreeNode *> children;   // it bydefault take datatype using in treeNode typenmae

    TreeNode( T data){
        this->data = data;
    }

    ~TreeNode(){
        for ( int i = 0; i< children.size(); i++){
            delete children[i]; // destruc called for its child nodes.
        }
    }

};