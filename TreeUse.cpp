#include <iostream>
#include "TreeNode.h"
#include <queue>
void printTree(TreeNode <int> * root){
    //this is the edge case, not base case, as in generic tree case , base is not require.

    if( root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);

    }

}

TreeNode<int> * takeInput(){

  int rootData;
  cout<<"Enter Data" <<endl;
  cin>> rootData;
  TreeNode<int> * root = new TreeNode<int>(rootData);
  int n;
  cout<< "Enter no. of Children of"<< rootData <<endl;
  cin>> n;

  for(int i=0;i<n;i++){
    TreeNode<int> * child= takeInput();
    root->children.push_back(child);
  }

  return root;
}

TreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<" Enter root data"<<endl;
    cin>> rootData;
    queue<TreeNode<int>*> pendingqueue;
    TreeNode<int> * root= new TreeNode<int>(rootData);
    pendingqueue.push(root);

    while(pendingqueue.size()!=0){
        TreeNode<int>* front =  pendingqueue.front();
        pendingqueue.pop();

        cout<<"Enter the No. of childer of "<< front->data<<endl;
        int frontChild;
        cin>>frontChild;
        for(int i = 0; i < frontChild; i++){
            int childData;
            cout << "Enter data of "<< i << "th child" << endl;
            cin >> childData;
            TreeNode <int>* child = new TreeNode<int>(childData);
            front->children.push_back( child );
            pendingqueue.push(child);
        }
    }

    return root;

}

void printTreeLevelWise( TreeNode<int> * root){
    queue<TreeNode<int>*>  pendingQueue;
    pendingQueue.push(root);
    while(pendingQueue.size()!=0){
        TreeNode<int> * front = pendingQueue.front();
        pendingQueue.pop();
        cout << front->data << ": ";
        int childSize = front->children.size();
        for( int i = 0; i < childSize; i++){
            TreeNode<int> * child = front->children[i];
            cout << child->data << " ";
            pendingQueue.push(child);
        }

        cout<<endl;
    
    }
    
}

int countNode( TreeNode<int> * root){
    if( root == NULL){
        return;
    }
    int ans = 1;
    for(int i = 0; i < root->children.size(); i++){
        ans += countNode(root->children[i]);
    }

    return ans;
}

int heightNode( TreeNode<int>* root){
    if ( root == NULL){
        return 0;
    }
    int height = 1;

    for( int i = 0; i < root->children.size(); i++){

        int n_height = heightNode( root->children[i]);
        if( n_height> height){
            height = n_height;
        }
        
    }

    return height+1;


}

void printAtLevelk( TreeNode<int> * root, int k){
    if( root == NULL){
        return ;
    }
    if( k == 0){
        cout<<" level" << root->data << " ";
        return;
    }
    
    for( int i = 0; i < root->children.size(); i++){
        printAtLevelk(root->children[i], k-1);
    }
    
    
}

int leafNode( TreeNode<int> * root){
    if( root == NULL){
        return 0;
    }
    
    if ( root->children.size() == 0){
        cout<< " leaf node "<< root->data;
        return 1;
    }
    int ans =0;
    
    for( int i = 0; i < root->children.size(); i++){
        ans += leafNode( root->children[i]);
    }
    
    return ans;
}

void preorder( TreeNode<int> * root){
    if(root == NULL){
        return ;
    }

    cout << root->data << endl;

    for( int i = 0; i < root->children.size(); i++){
        preorder(root->children[i]);
    }
}

void postorder( TreeNode<int> * root){
    if(root == NULL){
        return ;
    }

    for(int i = 0; i < root->children.size(); i++){
        postorder(root->children[i]);
    }

    cout<<root->data<<" ";
}

// void deleteTree_1( TreeNode<int> * root){                 it is one way of doing and second way is to implement desctructor in class.

//     for( int i = 0; i < root->children.size(); i++){
//         deleteTree_1(root->children[i]);
//     }

//     delete root;
// }




// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0   give all at input at once.

int main(){
    // TreeNode<int> * root = new TreeNode<int>(1);
    // TreeNode<int> * node1 = new TreeNode<int>(2);
    // TreeNode <int> * node2 = new TreeNode<int>(3);

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    // TreeNode<int>* root = takeInput();
    TreeNode<int> * root = takeInputLevelWise();
    // printTree(root);
    // printTreeLevelWise(root);
    preorder(root);

    delete root; // desturctor called

    return 0;



}