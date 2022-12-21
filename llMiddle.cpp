#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
node* takeInput(){
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;

    while(data!=-1){
        node* n=new node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

node* middle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    node* head=takeInput();
    node* middleElement=middle(head);
    cout<<middleElement->data;

}