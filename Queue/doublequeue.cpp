#include<iostream>
using namespace std;
class Dequeue
{
    int *arr;
    int front, rear, size;
    Dequeue(int n)
    {
        size=n;
        arr= new int[size];
        front=rear=-1;
    }
    bool pushfront(int data)
    {
        if((front==0 && rear==size-1)|| (rear== (front-1)%(size-1)))
        {
            cout<<"Queue is full !"<< endl;
            return false;
        }
        else if(front==-1)
        {
            rear=front=0;
        }
        else if(front==0 && rear!=size-1)
        {
            front=size-1;
        }
        else
        front--;
        arr[front]= data;
        return true;
    }
    bool pushrear(int data)
    {
        if((front==0 && rear==size-1)|| (rear== (front-1)%(size-1)))
        {
            cout<<"Queue is full !"<< endl;
            return false;
        }
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
        }
        else
        rear++;
        arr[rear]= data;
        return true;
    }
    int popfront()
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
    int poprear()
    {
         if(front == -1)
        {
           cout<<"Queue is empty"<< endl;
           return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear)
        {
           front=rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }
        return ans;
    }
};