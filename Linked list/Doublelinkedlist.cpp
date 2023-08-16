#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int val= this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
};

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<< temp->data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}
void InsertAtHead(Node* &head, int d)
{
    if(head==NULL)
    {
        Node* temp=new Node(d);
        head=temp;
    }
    else
    {
        Node* temp= new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void InsertAtTail(Node* &tail, int d)
{
   if(tail==NULL)
   {
        Node* temp=new Node(d);
        tail=temp;
   }
   else
   {
    Node* temp=new Node(d);
    temp -> prev = tail;
    tail -> next = temp;
    tail=temp;
   }
}
void Insert(Node* &head, Node* &tail, int pos, int d)
{
    Node* temp=head;
    if(pos==1)
    {
        InsertAtHead(head,d);
    }
    else
    {
        int c=1;
        while(c<(pos-1))
        {
            temp=temp->next;
            c++;
        }
        if(temp->next==NULL)
        {
            InsertAtTail(tail,d);
            return;
        }
        Node* nodeinsert=new Node(d);
        nodeinsert->next = temp->next;
        temp->next->prev = nodeinsert;
        temp->next = nodeinsert;
        nodeinsert->prev = temp;
    }
}
void Deletion(int pos,Node* &head)
 {
    int cnt=1;
    if(pos==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr= head;
        Node* prev= NULL;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
 }
int main()
{
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    InsertAtHead(head,15);
    print(head);
    InsertAtTail(tail,38);
    print(head);
    Insert(head,tail,3,89);
    print(head);
    Deletion(3,head);
    print(head);
    return 0;
}