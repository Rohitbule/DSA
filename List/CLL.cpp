#include<iostream>
#include<stdio.h>
using namespace std;
struct node 
{
    int item;
    node* next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL();
        CLL(CLL&);
        CLL& operator=(CLL&);
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void del(node *);
        ~CLL();
};
CLL::CLL()
{
    last=NULL;
}
CLL::CLL(CLL &c)
{
    node *t;
    if(c.last==NULL)
        last=NULL;
    else{
        t=c.last->next;
        while(t!=c.last)
        {
            insertAtLast(t->item);
            t=t->next;
        }
        insertAtLast(last->item);
    }

}
CLL& CLL::operator=(CLL &c)
{
    while(last)
        deleteFirst();
    node *t;
    if(c.last==NULL)
        last=NULL;
    else{
        t=c.last->next;
        while(t!=c.last)
        {
            insertAtLast(t->item);
            t=t->next;
        }
        insertAtLast(last->item);
    }
    return *this;
}
void CLL::insertAtStart(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CLL::insertAtLast(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
node* CLL::search(int data)
{
    node *t;
    if(last==NULL)
        return NULL;
    t=last->next;
    while(t!=last)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    if(last->item==data)
        return last;
    return NULL;
}
void CLL::insertAfter(node *t,int data)
{
    node *n;
    if(t==last)
        insertAtLast(data);
    else if(t){
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void CLL::deleteFirst()
{
    node *r;
    if(last)
    {
        r=last->next;
        last->next=r->next;
        if(last==r)
            last=NULL;
        delete r;
    }
}
void CLL::deleteLast()
{
    node *r,*t;
    if(last)
    {
        r=last;
        if(r->next==r)
            last=NULL;
        else
        {
            t=last->next;
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            last=t;
        }
        delete r;
    }
}
void CLL::del(node *t)
{
    node *r;
    if(t!=NULL){
        if(t==last)
            deleteLast();
        else if(t==last->next)
            deleteFirst();
        else
        {
            r=last->next;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
}
CLL::~CLL()
{
    while(last)
        deleteFirst();
}
