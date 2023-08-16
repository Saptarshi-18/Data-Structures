#include<iostream>
using namespace std;
int bin(int arr[], int s, int e, int k)
{
    int mid= s + (e-s)/2; // range
    if(arr[mid]==k)
    return mid;
    else if(arr[mid]>k)
    return bin(arr,s,mid-1,k);
    else
    return bin(arr,mid+1,e,k);
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int k=4;
    cout<< "The position of " << k << " is "<<  bin(arr,0,5,k) + 1 << endl;
    return 0;
}
