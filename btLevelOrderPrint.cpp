#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

TreeNode* levelWiseInput(){
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    TreeNode* root=new TreeNode(rootData);
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child data of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            TreeNode* leftChild=new TreeNode(leftChildData);
            pendingNodes.push(leftChild);
            front->left=leftChild;
        }

         cout<<"Enter right child data of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            TreeNode* rightChild=new TreeNode(rightChildData);
            pendingNodes.push(rightChild);
            front->right=rightChild;
        }

    }
    return root;
}

void printlevelOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
     queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
  }
}


int main(){
    TreeNode* root=levelWiseInput();
    printlevelOrder(root);
}