#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this-> data= d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* BuildTree(node* root)
{
    cout<<"Enter data "<< endl;
    int data;
    cin>>data;
    root=new node(data);
    
    if(data==-1)
    return NULL;

    cout<<"Enter data for inserting in left "<<data<< endl;
    root->left=BuildTree(root->left);
    cout<<"Enter data for inserting in right "<< data<< endl;
    root->right=BuildTree(root->right);
    return root;
}
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            //previous level traversed
            cout<<endl;
            if(!q.empty()) // queue still has nodes
            q.push(NULL);
        }
        else
        {
            cout<< temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node* root)
{
    if(root==NULL)
    return ;
    else
    {
        inorder(root->left);
        cout<< root->data << endl;
        inorder(root->right);
    }
}
void preorder(node* root)
{
    if(root==NULL)
    return ;
    else
    {
        cout<< root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root)
{
    if(root==NULL)
    return ;
    else
    {
        inorder(root->left);
        inorder(root->right);
        cout<< root->data << endl;
    }
}
void Buildlevlorder(node* &root)
{
    queue<node*> q;
    int data;
    cout<<"Enter data "<< endl;
    cin>> data;
    root = new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"Enter left node " << root->data << endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node " << root->data << endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    node* root=NULL;

    //creating a tree
    root= BuildTree(root);
    levelorder(root);
    cout<<"\n Inorder"<< endl;
    inorder(root);
    return  0;
}