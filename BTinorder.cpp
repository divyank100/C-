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

TreeNode* takeInput(){
    int rootData;
    cout<<"Enter the root data";
    cin>>rootData;

    TreeNode* root= new TreeNode(rootData);
    queue<TreeNode*>pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        
        int leftchildData;
        cout<<"Enter left child of  "<<front->data;
        cin>>leftchildData;
        
        if(leftchildData!=-1){
            TreeNode* child=new TreeNode(leftchildData);
            front->left=child;
            pendingNodes.push(child);
        }

        int rightchildData;
        cout<<"Enter right child of  "<<front->data;
        cin>>rightchildData;
        
        if(rightchildData!=-1){
            TreeNode* child=new TreeNode(rightchildData);
            front->right=child;
            pendingNodes.push(child);
        }

    }
    return root;
}


void printTreeLevelwise(TreeNode* root){
    queue<TreeNode*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<" ";
            
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data<<" ";
            
            pendingNodes.push(front->right);
        }
        cout<<endl;


    }
}

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

void preOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}



int main(){
     TreeNode* root=takeInput();
     preOrder(root);
    //  printTreeLevelwise(root);
}

