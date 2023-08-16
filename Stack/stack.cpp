#include<iostream>
/// #include<stack> for STL
using namespace std;
class Stack
{
    //properties
    int *arr;
    int top;
    int size;

    //behavior
    public:
     Stack(int size)
     {
        this->size=size;
        arr= new int[size];
        top=-1;
     }


     void push(int element)
     {
        if((size-top)>1)
        {
            top++;
            arr[top]=element;
        }
        else
        {
            cout<< " Stack Overflow" << endl;
            return;
        }

     }


     void pop()
     {
        if(top==-1)
        {
            cout << "Stack Underflow" << endl;
        }
        
        else
        {
            top--;
        }

     }


     int peek()
     {
        if(top>=0)
        return arr[top];
        else
        {
            cout << "Stack Empty" << endl;
             return -1;
        }

     }


     bool Empty()
     {
        if(top==-1)
        return false;
     }

};
int main()
{
    //Stack using STL

    /*stack<int> s;
    
    s.push(2);
    
    s.push(3);
    
    s.push(4);

    s.pop();
    
    if(s.empty())
    cout<< "Stack is empty" <<  endl;
    else
    cout<< s.top() <<  endl;
    cout << "Size of stack " << s.size() << endl; */

    //Stack using class

    Stack s(5);
    s.push(22);
    s.push(33);
    s.push(44);

    cout << s.peek() << endl;

    s.pop();

    cout << s.peek() << endl;

    return 0;
}