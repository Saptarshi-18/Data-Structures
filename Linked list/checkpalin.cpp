/* Checking palindrome using a single linked list*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int d)//constructor
    {
        this-> data= d;
        this-> next=NULL;
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
void InsertAtHead(Node* &head, int d)
 {
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;
 }
 
 void print(Node* &head)
 {
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<< temp->data << " ";
        temp=temp->next;
    }
    cout<< endl;
 }
Node* getmid(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* rev(Node* head)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalin(Node* head)
{
    Node* mid=getmid(head);
    Node* temp= mid->next;
    mid->next=rev(temp);
    Node* head1= head;
    Node* head2= temp;
    while(head2!=NULL && head1!=NULL)
    {
        if(head1->data!=head2->data)
        return false;
        else
        {
            head1=head1->next;
            head2=head2->next;
        }
    }
    mid->next=rev(temp);
    return true;
}
int main()
{
    Node* h=new Node(1);
    InsertAtHead(h,2);
    InsertAtHead(h,2);
    InsertAtHead(h,1);
    print(h);
    bool t= isPalin(h);
    cout<< (bool) t << endl;
}