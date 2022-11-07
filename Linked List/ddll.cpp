#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n= new node(val);
    if(head!=NULL)
    {   
         head->prev=n;
    }
    
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}



void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    display(head);
    return 0;
}