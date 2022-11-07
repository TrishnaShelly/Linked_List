//time complexity in reccurence relation f(n)=f(n-1)+f(n-2)
//t(n)=at(n/b)+Q(n)
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
        next=NULL;
    }
};

void evenafterodd(node* &head)
{
    node* odd=head;
    node* even = head->next;
    node* evenStart= even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
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

int main()
{
    node *head=NULL;
    for(int i =0;i<6;i++)
    {
        insertAtTail(head,i);
    }
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}