#include<iostream>
#include<stdio.h>
using namespace std;
#define UNDERFLOW 1
struct node
{
    node* prev;
    int item;
    node* next;
};
class Deque
{
    private:
        node *front,*rear;
    public:
        Deque();
        Deque(Deque &);
        Deque& operator=(Deque &);
        ~Deque();
        bool isEmpty();
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        int getRear();
        int getFront();

};
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
Deque::Deque(Deque &d)
{
    node *t;
    front=rear=NULL;
    if(d.front==NULL);
        
    else
    {
        t=d.front;
        while(t!=NULL)
        {
            insertRear(t->item);
            t=t->next;
        }
    }
}
Deque& Deque::operator=(Deque &d)
{
    while(front)
        deleteFront();
    node *t;
    if(d.front==NULL)
        front=rear=NULL;
    else
    {
        t=d.front;
        while(t!=NULL)
        {
            insertRear(t->item);
            t=t->next;
        }
    }
    return *this;
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
bool Deque::isEmpty()
{
    return front==NULL;
}
void Deque::insertFront(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=front;
    if(front==NULL)
    {
        front=rear=n;
    }
    else
    {
        front->prev=n;
        front=n;
    }
}
void Deque::insertRear(int data)
{
    node *n=new node;
    n->next=NULL;
    n->item=data;
    n->prev=rear;
    if(rear==NULL)
    {
        front=rear=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }
}
void Deque::deleteFront()
{
    if(front==NULL)
        throw UNDERFLOW;
    if(front==rear)
    {
        delete front;
        front=rear=NULL;
    }
    else
    {
        front=front->next;
        delete front->prev;
        front->prev=NULL;
    }
}
void Deque::deleteRear()
{
    if(rear==NULL)
        throw UNDERFLOW;
    if(rear==front)
    {
        delete rear;
        front=rear=NULL;
    }
    else
    {
        rear=rear->prev;
        delete rear->next;
        rear->next=NULL;
    }
}
int Deque::getFront()
{
    if(front==NULL)
        throw UNDERFLOW;
    return front->item;
}
int Deque::getRear()
{
    if(rear==NULL)
        throw UNDERFLOW;
    return rear->item;
}
