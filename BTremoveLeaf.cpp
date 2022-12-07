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

void isPresent(TreeNode* root,int k1,int k2){
    if(root==NULL){
        return;
    }
    int mini=min(k1,k2);
    int maxi=max(k1,k2);

    if(root->data>=mini && root->data<=maxi){
        cout<<root->data<<" ";
    }
    if(root->data>=mini){
        isPresent(root->left,k1,k2);
    }
    if(root->data<=maxi){
        isPresent(root->right,k1,k2);
    }

}

int main(){
    TreeNode* root=takeInput();
    cout<<endl;
    int k1,k2;
    cin>>k1>>k2;
    isPresent(root,k1,k2);
}

