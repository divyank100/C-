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


void makeArray(TreeNode* root,vector<int>* arr){
      if (root==NULL){
          return;
      }
      arr->push_back(root->data);
      makeArray(root->left,arr);
      makeArray(root->right,arr);
}

vector<int>* sorting(vector<int>* arr){
    sort(arr->begin(),arr->end());
    return arr;
}

void pairSum(vector<int>* arr,int sum){
    int i=0;
    int j=arr->size()-1;
    while(i<j){
        if(arr->at(i)+arr->at(j)==sum){
            cout<<arr->at(i)<<" "<<arr->at(j)<<endl;
            i++;
            j--;
        }
        if(arr->at(i)+arr->at(j)>sum){
            j--;
        }
        if(arr->at(i)+arr->at(j)<sum){
            i++;
        }
    }

}

int main(){
    TreeNode* root=takeInput();
    vector<int>* arr= new vector<int>();
    makeArray(root,arr);
    arr=sorting(arr);
    int sum;
    cout<<"Enter SUM:";
    cin>>sum;
    pairSum(arr,sum);


    
    
    
    
    
}