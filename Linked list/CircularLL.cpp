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
void Insert(Node* &tail, int element, int d)
{
    //empty list
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }
    else
    {
        Node* curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node* &tail)
{
    Node* temp=tail;
    if(tail==NULL)
    {
        cout<< "List is empty" << endl;
        return;
    }
    do
    {
        cout<< tail->data << " ";
        tail=tail->next;
    } while (tail!=temp);
    cout<< endl;
}
void Delete(Node* &tail, int d)
{
    //empty list tail=NULL
    if(tail==NULL)
    {
        cout<< "List is empty"<< endl;
        return;
    }
    else
    {
        Node* prev=tail;
        Node* curr= prev->next;
        while(curr->data!=d)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(tail==curr)
        tail=prev;
        //one node linked list
        else if(curr==prev)
        tail=NULL;
        else
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* tail=NULL;
    Insert(tail,3,5);
    Insert(tail,5,100);
    print(tail);
    Delete(tail,5);
    print(tail);
    return 0;
}