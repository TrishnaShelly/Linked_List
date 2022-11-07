#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next= NULL;
    }

};

void insertAtHead(node* &head ,int val)
{
    node* n = new node(val);
    n->next = head;
    head=n;
}

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return ;
    }
    node* temp = head;
    while( temp->next!=NULL)
    {
            // cout<<"chalda yr main ta";

        temp = temp->next;
    }
     temp->next = n;
}

void display(node* head)
{
    node* temp =head;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* reverse(node* &head)
{
    node* prev=NULL;
    node* curr = head;
    node* next;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main()
{
    node* head= NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,9);
    display(head);
    cout<<endl;
    head=reverse(head);
    display(head);
}