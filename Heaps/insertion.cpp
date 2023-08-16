#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size=0;

    void insert(int val)
    {
        size++;
        int index=size;
        arr[index]=val;

        while (index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            return;
        }
        
    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<< arr[i] << ", ";
        }
        cout<< endl;
    }
    void deletefromHeap()
    {
        if(size==0)
        {
            cout<<"empty"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size)
        {
            int leftindex=2*i, rightindex=2*i+1;
            if(leftindex<size && arr[i]<arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[i]<arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i=rightindex;
            }
            else
            return;
        }
    }
};
void heapify(int arr[], int size, int i)
{
    int largest=i;
    int  left= 2*i;
    int right = 2*i +1;

    if(left<size && arr[largest]<arr[left])
    largest=left;

    if(right<size && arr[largest]<arr[right])
    largest=right;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.deletefromHeap();
    h.print();

    int array[6]={-1,54,53,55,52,50};

    for(int i=5/2;i>0;i--)
    heapify(array,5,i);

    for(int i=1;i<=5;i++)
    cout<<array[i]<<" ";
    return 0;
}