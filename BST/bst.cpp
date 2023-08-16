#include<queue>
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node*  right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertBST(Node* root, int d)
{
    if(root==NULL)
    {
        root= new Node(d);
        return root;
    }
    if(d>root->data)
    {
         //right mein insert
         root->right= insertBST(root->right, d);
    }
    else
    {
        //left mein
        root->left= insertBST(root->left, d);
    }
    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=insertBST(root, data);
        cin>> data;
    }
}
void levelorder(Node* &root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp=q.front();
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
void inorder(Node* root)
{
    if(root==NULL)
    return ;
    else
    {
        inorder(root->left);
        cout<< root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root)
{
    if(root==NULL)
    return ;
    else
    {
        cout<< root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root==NULL)
    return ;
    else
    {
        inorder(root->left);
        inorder(root->right);
        cout<< root->data << " ";
    }
}

Node* minVal(Node* root)
{
        Node* temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
    
}

Node* maxVal(Node* root)
{
        Node* temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp;
    
}

Node* deleteBST(Node* root, int val)
{
    if(root==NULL)
    return root;
    if(root->data==val)
    {
        if(root->left==NULL & root->right==NULL) // if 0 child
        {
            delete root;
            return NULL;
        }
        // 1 child 

        // left child
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL)
        {
            int mini= minVal(root->right)->data;
            root->data=mini;
            root->right=deleteBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val)
    {
        root->left=deleteBST(root->left, val);
        return root;
    }
    else
    {
        root->right=deleteBST(root->right, val);
        return root;
    }
}

int main()
{
    Node* root=NULL;
    cout<<"Enter data to create bst"<< endl;
    takeInput(root);
    cout<< "Printing BST "<< endl;
    levelorder(root);
    cout<<"Printing inorder"<< endl;
    inorder(root);
    cout<<endl;
    cout<<"Printing preorder"<< endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing postorder"<< endl;
    postorder(root);
    cout<<endl;
    cout<<"Min value"<< endl;
    cout<<minVal(root)->data<< endl;
    cout<<"Max value"<< endl;
    cout<<maxVal(root)->data<< endl;
    root=deleteBST(root,30);
    cout<< "Printing BST "<< endl;
    levelorder(root);
    return 0;
}