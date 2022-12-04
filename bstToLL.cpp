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
    node* next;

    node(int val){
        data=val;
        next=NULL;
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

void addTail(int val,node* &head,node* &tail){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        tail=n;
    }
    else{
        tail->next=n;
        tail=tail->next;
    }
}

void solve(TreeNode* root,node* &head, node* &tail){
    if(root==NULL){
        return;
    }
    solve(root->left,head,tail);
    addTail(root->data,head,tail);
    solve(root->right,head,tail);
}

node* bstToll(TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    node* head=NULL;
    node* tail=NULL;

    solve(root,head,tail);
    return head;
}


int main(){
    TreeNode* root=takeInput();
    cout<<endl;
    cout<<endl;
    node* head=bstToll(root);

    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"END";
}

