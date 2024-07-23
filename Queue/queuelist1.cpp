#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_LIST 1
struct node 
{
    int item;
    node *next;
};
class Queue
{
    private:
        node *front; //start
        node *rear;
    public:
        Queue();
        Queue(Queue&);
        Queue& operator=(Queue&);
        void insert(int);
        int getRear();
        int getFront();
        void del();
        ~Queue();
        int count();
};
Queue::Queue()
{
    front=NULL;
    rear=NULL;
}
Queue::Queue(Queue &q)
{
    
    front=rear=NULL;
    node *t;
    t=q.front;
    while(t!=NULL)
    {
        insert(t->item);
        t=t->next;
    }
    
}
Queue& Queue::operator=(Queue &q)
{
    while(front)
        del();

    node *t;
    t=q.front;
    while(t!=NULL)
    {
        insert(t->item);
        t=t->next;
    }
}
void Queue::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(rear==NULL)
    {
        front=n;
        rear=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }
}
int Queue::getRear()
{
    if(rear==NULL)
        throw EMPTY_LIST;
    return rear->item;
}
int Queue::getFront()
{
    if(front==NULL)
        throw EMPTY_LIST;
    return front->item;
}
void Queue::del()
{
    if(front==NULL)
        throw EMPTY_LIST;
    if(front==rear)
    {
        delete front;
        front=NULL;
        rear=NULL;
    }
    else
    {
        node *t=front;
        front=front->next;
        delete t;
    }
}
Queue::~Queue()
{
    while(front)
        del();
}
int Queue::count()
{
    node *t;
    int c=0;
    t=front;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}
