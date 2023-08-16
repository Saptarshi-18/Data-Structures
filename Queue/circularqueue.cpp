#include<iostream>
using namespace std;
class CircularQueue
{
    int *arr;
    int front, rear, size;
    public:
    CircularQueue()
    {
        size=100000; // hypothetical. In case of parametrized constructor we declare a dynamic array
        arr= new int[size];
        front =rear= -1;
    }
    bool enqueue(int data)
    {
        if((front==0 && rear==size-1)|| (rear== (front-1)%(size-1)))
        cout<<"Queue is full !"<< endl;
        else if(front==-1)
        {
          rear=front=0;
          arr[rear]=data;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=data;
        }
        else
        {
            rear++;
        }
        arr[rear]=data;
        return true;
    }
    int dequeue()
    {
        if(front == -1)
        {
           cout<<"Queue is empty"<< endl;
           return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear)
        {
           front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};