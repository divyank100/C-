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

node* print(node* head,int i){
    int length=0;
    int count=0;
    node* ptr=head;
    node* start=head;
    while(ptr->next!=NULL){
        length++;
        ptr=ptr->next;
    }
    // cout<<length;
    node* temp=head;
    while(count<length-i){
        temp=temp->next;
        count++;
    }
    node* a=temp->next;
    temp->next=NULL;
    head=a;
    ptr->next=start;
    
  return head;
}

void print2(node* head){
    // cout<<head->data<<endl;
      node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}
int main(){
    int i;
    cin>>i;
node* head=takeInput();
head=print(head,i);
print2(head);

}