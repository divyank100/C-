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

node* deleteNodes(node* head,int n,int m){
node* tail=head;
    while(head!=NULL){
    int count=1;
    
    while(count<m){
     tail=tail->next;
     count++;
    }
    int count2=1;
    node* ptr=tail->next;
    while(count2<=n){
        ptr=ptr->next;
        count2++;
    }
    tail->next=ptr;
    }
    return head;

}


void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

int main(){
    node* head=takeInput();
     int m;
    cin>>m;
    int n;
    cin>>n;
    head=deleteNodes(head,n,m);
    print(head);

}