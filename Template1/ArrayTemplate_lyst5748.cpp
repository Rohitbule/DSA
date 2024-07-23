#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
template <class X>
class Array
{
    private:
        int capacity;
        int lastIndex;
        X *ptr;
    public:
        Array();        
        Array(Array &);
        Array& operator=(Array &);
        void createArray(int);
        void insert(int,X);
        void append(X);
        X getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
        void edit(int,X);
        int count();
        int getCapacity();
        ~Array();
};
template<class X>
Array<X>::Array()
{
    ptr=NULL;
}
template <class X>
Array<X>::Array(Array<X> &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
template <class X>
Array<X>& Array<X>::operator=(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
template <class X>
void Array<X>::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new X[capacity];
}
template <class X>
void Array<X>::append(X data)
{
    if(!isFull())
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else
        cout<<"\nOverflow: appned not performed"<<endl;
}
template <class X>
bool Array<X>::isFull()
{
    return lastIndex==capacity-1;
}
template <class X>
bool Array<X>::isEmpty()
{
    return lastIndex==-1;
}
template <class X>
void Array<X>::insert(int index,X data)
{
    int i;
    try{
        if(index<0 || index>lastIndex+1)
            throw 1;
        if(isFull())
            throw 2;
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;        
    }
    catch(int e){
        if(e==1)
            cout<<"Invalid Index";
        else if(e==2)
            cout<<"Overflow";
    }
        
}
template <class X>
X Array<X>::getItem(int index)
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
    
}
template <class X>
int Array<X>::getCapacity()
{
    return capacity;
}
template <class X>
int Array<X>::count()
{
    return lastIndex+1;
}
template <class X>
void Array<X>::edit(int index,X newData)
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
template <class X>
void Array<X>::del(int index)
{
    int i;
    try{
        if(index<0||index>lastIndex)
            throw 1;
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or underflow";
    }
}
template <class X>
Array<X>::~Array()
{
    delete []ptr;
}
int main()
{
    Array <int>obj1;
    Array<float>obj2;
    Array<string>obj3;
    obj1.createArray(5);
    obj2.createArray(4);
    obj3.createArray(3);
    

    obj1.append(10);
    obj1.append(20);
    obj1.append(30);
    for(int i=0;i<obj1.count();i++)
        cout<<obj1.getItem(i)<<"  ";
    cout<<endl;
    obj2.append(2.5f);
    obj2.append(4.5f);
    obj3.append("Rahul");
    obj3.append("Harish");
    cout<<obj1.getItem(0)<<endl;
    cout<<obj2.getItem(0)<<endl;
    cout<<obj3.getItem(0);
    cout<<endl;
    Array<string> obj4=obj3;
    cout<<obj4.count();
    return 0;

}