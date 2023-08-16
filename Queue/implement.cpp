#include<iostream>
using namespace std;
class  Queue
{
    public:
    int *arr;
    int front,rear,size;
    Queue()
    {
        size=100000; //hypothetical
        arr= new int[size];
        front=rear=0;
    }
    void Enqueue(int data)
    {
        if(rear==size)
        cout<<"Queue is Full!"<< endl;
        else
        {
            arr[rear]=data;
            rear++;
        }
    }
    int Dequeue()
    {
        if(front==rear)
        return -1;
        else
        {
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear)
            {
                front=0;
                rear=0;
            }
            return ans;
        }
    }
    int qfront()
    {
        if(front==rear)
        return -1;
        else
        return arr[front];
    }
    bool empty()
    {
        if(front==rear)
        return true;
        else
        return false;
    }
};