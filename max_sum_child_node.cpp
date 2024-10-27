#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <queue>
#include <cstdlib>
using namespace std; 

TreeNode<int> * takeInputLevelWise(){
    int data;
    cout<< "enter root data"<<endl;
    cin>>data;
    TreeNode<int> * root = new TreeNode<int>(data);
    queue< TreeNode<int>*> pendingqueue;
    pendingqueue.push(root);
    while(pendingqueue.size()!=0){
        TreeNode<int> * front = pendingqueue.front();
        pendingqueue.pop();
        int childno;
        cout<< "enter number of child of "<<front->data <<  endl;
        cin>>childno;

        for( int i = 0 ;i < childno; i++){
            
            int child;
            cout<<" enter data of child " << i << endl;
            cin>> child;
            TreeNode<int> * childNode = new TreeNode<int>(child);
            front->children.push_back(childNode);
            pendingqueue.push(childNode);
        }

    }

    return root;

}


TreeNode<int> * max_sum_node(TreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    TreeNode<int> * maxNode = root;
    int maxSum=0;


    queue<TreeNode<int>*> pendingqueue;
    pendingqueue.push(root);
    while(pendingqueue.size()!=0){
        TreeNode<int>* front = pendingqueue.front();
        int childsum=0;

        pendingqueue.pop();
        
        for(int i = 0;i< front->children.size();i++){
            childsum+=front->children[i]->data;
            pendingqueue.push(front->children[i]);
        }

        if(childsum> maxSum){
            maxSum=childsum;
            maxNode=front;
        }

    }


    return maxNode;
}

TreeNode<int> * next_greater(TreeNode<int>* root, int x){
    if(root == NULL){
        return 0;
    }
    TreeNode<int> * nextNode= root;
    int ans = abs(x-root->data);

    queue<TreeNode<int>*> pendingqueue;
    pendingqueue.push(root);
    while(pendingqueue.size()!=0){
        TreeNode<int>* front = pendingqueue.front();
        pendingqueue.pop();
        int child_next= abs(x-front->data);
        if( child_next < ans){
            ans=child_next;
            nextNode=front;

        }

        for(int i=0; i< front->children.size();i++)
        {
            pendingqueue.push(front->children[i]);
        }
    }

    return nextNode;
}

TreeNode<int> * next_gre_rec(TreeNode<int>* root, int x){
    if(root == NULL){
        return 0;
    }

    TreeNode<int>* ans= root->data>x?root:NULL;

    for(int i=0;i< root->children.size(); i++){
        TreeNode<int> * temp= next_gre_rec(root->children[i],x);
    if(ans==NULL){
        ans=temp;
    }
    else{
        if( temp->data < ans->data){
            ans=temp;
        }
    }
    }

    return ans;

}


// int sec_max(TreeNode<int>* root, int max1, int max2){
//     if(root==NULL){
//         return NULL;
//     }

//     if (root->data > max1){
//         max2 = max1;
//         max1 = root->data;
//     }
//     else{
//         if(root->data > max2 && root->data<  max1){
//             max2 = root->data;
//         }
//     }

//     for( int i = 0; i < root->children.size(); i++){
//         sec_max(root->children[i], max1, max2);
//     }

//     return max2;
    
// }


TreeNode<int> * depth_replace(TreeNode<int> * root, int d){
    if(root == NULL){
        return 0;
    }

    root->data = d;

    for(int  i = 0 ; i < root->children.size(); i++){
        depth_replace(root->children[i], d+1);
    }

    return root;


}


int main(){
      TreeNode<int> * root = takeInputLevelWise();
    //   cout<< max_sum_node(root);
    cout<<next_greater(root,5)->data;
}
