#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
    int item;
    node* next;
};
class SLL{
    private:
        node *start;
    public:
        SLL();
        SLL(SLL&);
        SLL& operator=(SLL &);
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* search(int);
        void deleteFirst();
        void deleteLast();
        void delNode(node*);
        ~SLL();
};
SLL::SLL()
{
    start=NULL;
}
SLL::SLL( SLL &list)
{
    node *t;
    t=list.start;
    start=NULL;
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
}
SLL& SLL::operator=(SLL &list)
{
    node *t;
    t=list.start;
    while(start)
        deleteFirst();

    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
    return *this;
}
void SLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::insertAtLast(int data)
{
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;

    if(start==NULL)
        start=n;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
node* SLL::search(int data)
{
    node*t;
    t=start;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void SLL::insertAfter(node *t,int data)
{
    node *n;
    if(t)
    {
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }

}
void SLL::deleteFirst()
{
    node*r;
    if(start)
    {
        r=start;
        start=r->next;
        delete r;
    }
}
void SLL::deleteLast()
{
    node *t;
    try{
        if(start==NULL)
            throw 1;
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start;
            while(t->next->next!=NULL)
                t=t->next;
            delete t->next;
            t->next=NULL;
        }
    }
    catch(int e)
    {

    }

}
void SLL::delNode(node *t)
{
    node *r;
    try{
        if(start==NULL)
            throw 1;
        if(start==t)
            deleteFirst();
        else
        {
            r=start;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;            
        }
    }
    catch(int e){}
}
SLL::~SLL()
{
    while(start)
        deleteFirst();
}
