#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_STACK 1
struct node
{
    int item;
    node *next;
};
class Stack
{
    private:
        node *top;
    public:
        Stack();
        Stack(Stack &);
        Stack& operator=(Stack&);
        void push(int);
        int peek();
        void pop();
        void reverse();
        ~Stack();
};
Stack::Stack()
{
    top=NULL;
}
Stack::Stack(Stack &s)
{
    node *t;
    s.reverse();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reverse();
}
Stack& Stack::operator=(Stack &s)
{
    if(top!=NULL)
    {
        while(top)
            pop();
    }
    node *t;
    s.reverse();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reverse();
    return *this;
}
void Stack::push(int data)
{
    node *n;
    n=new node;
    n->item=data;
    n->next=top;
    top=n;
}
int Stack::peek()
{
    if(top==NULL)
        throw EMPTY_STACK;
    return top->item;
}
void Stack::pop()
{
    node *r;
    if(top!=NULL)
    {
        r=top;
        top=top->next;
        delete r;
    }
}
void Stack::reverse()
{
    Stack s1;
    while(top)
    {
        s1.push(peek());
        pop();
    }
    top=s1.top;
    s1.top=NULL;
}
Stack::~Stack()
{
    while(top)
        pop();
}
