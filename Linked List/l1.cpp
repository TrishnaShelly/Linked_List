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

void delteAtHead(node* &head)
{
    node* toDelete =head;
    head=head->next;

    delete toDelete;
}
void deletion(node* &head,int val)
{
    if(head==NULL)
    return;
    if(head->next==NULL)
    delteAtHead(head);
    node* temp =head;

    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node * toDelete =temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

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

int main()
{
    node* head= NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,9);
    display(head);
    cout<<endl;
    // del./l12teAtHead(head);
    display(head);
    // cout<<"chalda y./r main ta";
    return 0;
}