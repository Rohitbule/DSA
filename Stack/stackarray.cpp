#include<iostream>
#include<stdio.h>
using namespace std;
#define STACK_IS_EMPTY 1
class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack();
        Stack(int);
        Stack(Stack&);
        Stack& operator=(Stack&);
        void createStack(int);
        void push(int);
        bool isFull();
        int peek();
        bool isEmpty();
        void pop();
        ~Stack();
};
Stack::Stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
Stack::Stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
Stack::Stack(Stack &s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
}
Stack& Stack::operator=(Stack &s)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
    return *this;
}
void Stack::createStack(int cap)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
void Stack::push(int data)
{
    if(isFull())
        cout<<"\nStack Overflow";
    else
    {
        top++;
        ptr[top]=data;
    }
}
bool Stack::isFull()
{
    return top==capacity-1;
}
int Stack::peek()
{
    if(isEmpty())
        throw STACK_IS_EMPTY;
    return ptr[top];
}
bool Stack::isEmpty()
{
    return top==-1;
}
void Stack::pop()
{
    if(isEmpty())
        cout<<"\nStack Underflow";
    else
    {
        top--;
    }
}
Stack::~Stack()
{
    if(ptr!=NULL)
        delete []ptr;
}
