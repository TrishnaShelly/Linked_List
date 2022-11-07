#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
    node(int val)
    {
        value = val;
        next = NULL;
    }
};

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node  * n = new node(val);
    if(head==NULL)
    {
        insertAthead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

node* reverseK(node* &head, int k)
{
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
   head->next= reverseK(nextptr,k);
   return prev;
}

void display(node* head)
{
    node* temp =head;
    while(temp!= NULL)
    {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

int main()
{
    node* head= NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    head=reverseK(head,2);
    display(head);
    return  0;
}