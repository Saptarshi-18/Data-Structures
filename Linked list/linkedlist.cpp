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
    ~Node()//destructor
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

 void InsertAtTail(Node* &tail, int d)
 {
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
 }
 void InsertAtPos(int pos, Node* &head, Node* &tail, int d)
 {
    if(pos==1)
    {
        InsertAtHead(head,d);
    }
    Node* temp=head;
    int c=1;
    while(c<(pos-1)) // traversal to targeted node
    {
        temp=temp->next;
        c++;
    }
    
    //creating node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return;
    }
 }
 void Deletion(int pos,Node* &head)
 {
    int cnt=1;
    if(pos==1)
    {
        Node* temp=head;
        head=head->next;
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
    InsertAtHead(head, 15);
    InsertAtTail(tail,22);
    print(head);// prints entire linked list
    Deletion(2,head);
    print(head);
    return 0;
}