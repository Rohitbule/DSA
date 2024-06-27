#include<stdio.h>
#include<iostream>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray();
        DynArray(DynArray &);
        DynArray& operator=(DynArray &);
        void createArray(int);
        void insert(int,int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
        void edit(int,int);
        int count();
        int getCapacity();
        ~DynArray();
};
DynArray::DynArray(){
    ptr=NULL;
}
DynArray::DynArray(DynArray&arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
DynArray& DynArray::operator=(DynArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
void DynArray::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
}
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
        
}
bool DynArray::isFull()
{
    return lastIndex==capacity-1;
}
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
void DynArray::insert(int index,int data)
{
    int i;
    try{
        if(index<0 || index>lastIndex+1)
            throw 1;
        if(isFull())
            doubleArray();
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;        
    }
    catch(int e){
        if(e==1)
            cout<<"Invalid Index";
    }
        
}
int DynArray::getItem(int index)
{
    try{
        if(index<0||index>lastIndex)
            throw 1;
        return ptr[index];
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or Array is empty";
    }
    return -1;
}
int DynArray::getCapacity()
{
    return capacity;
}
int DynArray::count()
{
    return lastIndex+1;
}
void DynArray::edit(int index,int newData)
{
    try{
        if(index<0||index>lastIndex)
            throw 1;
        ptr[index]=newData;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index";
    }
}
void DynArray::del(int index)
{
    int i;
    try{
        if(index<0||index>lastIndex)
            throw 1;
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if( capacity>1 && lastIndex+1 <=capacity/2)
            halfArray();
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or underflow";
    }
}
DynArray::~DynArray()
{
    delete []ptr;
}
void DynArray::doubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void DynArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
