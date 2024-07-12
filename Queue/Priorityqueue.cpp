#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_QUEUE 1
struct node
{
    int pno;
    int item;
    node *next;
};
class PriorityQueue
{
    private:
        node *start;
    public:
        PriorityQueue();
        PriorityQueue(PriorityQueue &);
        PriorityQueue& operator=(PriorityQueue &);
        ~PriorityQueue();
        void insert(int,int);
        void del();
        int getItem();
        int getHighestPriority();
        bool isEmpty();
};
PriorityQueue::PriorityQueue()
{
    start=NULL;
}
PriorityQueue::PriorityQueue(PriorityQueue &pq)
{
    node *t;
    start=NULL;
    if(pq.start)
    {
        t=pq.start;
        while(t!=NULL)
        {
            insert(t->pno,t->item);
            t=t->next;
        }
    }
}
PriorityQueue& PriorityQueue::operator=(PriorityQueue &pq)
{
    while(start)
        del();
    node *t;
    if(pq.start)
    {
        t=pq.start;
        while(t!=NULL)
        {
            insert(t->pno,t->item);
            t=t->next;
        }
    }
    return *this;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        del();
}
void PriorityQueue::insert(int p,int data)
{
    node *n=new node;
    n->pno=p;
    n->item=data;
    node *t;
    if(start==NULL || start->pno < n->pno)
    {
        n->next=start;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
        {
            if(t->next->pno < n->pno)
                break;
            t=t->next;
        }
        n->next=t->next;
        t->next=n;
    }
}
void PriorityQueue::del()
{
    node *t;
    if(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
int PriorityQueue::getItem()
{
    if(start)
        return start->item;
    throw EMPTY_QUEUE;
}
int PriorityQueue::getHighestPriority()
{
    if(start)
        return start->pno;
    throw EMPTY_QUEUE;

}
bool PriorityQueue::isEmpty()
{
    return start==NULL;
}
