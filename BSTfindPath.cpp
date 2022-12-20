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

class node{
    public:
    int data;
    node* next=NULL;

    node(int val){
        data=val;
        next=NULL;
    }
};

TreeNode* takeInput(){
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    TreeNode* root=new TreeNode(rootData);
    queue<TreeNode*>pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        
        int leftChildData;
            cout<<"Enter Left child of "<<front->data<<" ";
            cin>>leftChildData;
        if(leftChildData!=-1){
            TreeNode* child=new TreeNode(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }

        int rightChildData;
            cout<<"Enter Right child of "<<front->data<<" ";
            cin>>rightChildData;
        if(rightChildData!=-1){
            TreeNode* child=new TreeNode(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;

}

void printTree(TreeNode* root){
    
    queue<TreeNode*>pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        TreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}

vector<int>* findpath(TreeNode* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data==root->data){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    if(data > root->data){
        vector<int>* rightOutput=findpath(root->right,data);
        if(rightOutput!=NULL){
            rightOutput->push_back(root->data);
            return rightOutput;
        }
    }
    
    if(data < root->data){
        vector<int>* leftOutput=findpath(root->left,data);
        if(leftOutput!=NULL){
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    }
    else{
        return NULL;
    }
}



int main(){
    TreeNode* root=takeInput();
    int data;
    cout<<"Enter the data :";
    cin>>data;
    vector<int>* output=findpath(root,data);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
    }
    delete output;
    
    
}