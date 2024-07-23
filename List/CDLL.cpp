#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL{
    private:
        node *start;
    public:
        CDLL();
        CDLL(CDLL &);
        ~CDLL();
        CDLL & operator=(CDLL &);
        void insertAtStart(int);
        void insertAtLast(int);
        node * search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void del(node *temp);
};
CDLL::CDLL()
{
    start=NULL;
}
CDLL::CDLL(CDLL &d)
{
    node *t;
    if(d.start==NULL)
        start=NULL;
    else
    {
        t=d.start;
        do
        {
            insertAtLast(t->item);
            t=t->next;
        } while (t!=d.start);
    }
}
CDLL::~CDLL(){
    while(start)
        deleteFirst();
}
CDLL& CDLL::operator=(CDLL &d)
{
    while(start)
        deleteFirst();
    
    node *t;
    if(d.start==NULL)
        start=NULL;
    else
    {
        t=d.start;
        do
        {
            insertAtLast(t->item);
            t=t->next;
        } while (t!=d.start);
    }
    return *this;
}
void CDLL::insertAtStart(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void CDLL::insertAtLast(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
node* CDLL::search(int data)
{
    node *t;
    if(start==NULL)
        return NULL;
    t=start;
    do
    {
        if(t->item==data)
            return t;
        t=t->next;
    }while(t!=start);
    return NULL;
}
void CDLL::insertAfter(node *temp,int data)
{
    node *n,*t;
    if(start==NULL||temp==NULL)
        cout<<"Insertion cannot be performed";
    else
    {
        n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}
void CDLL::deleteFirst()
{
    node *r;
    if(start!=NULL)
    {
        r=start;
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            start->prev->next=r->next;
            start=start->next;
            start->prev=r->prev;
            delete r;
        }
    }
}
void CDLL::deleteLast()
{
    node *r;
    if(start!=NULL)
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            r=start->prev;
            r->prev->next=start;
            start->prev=r->prev;
            delete r;
        }
    }
}
void CDLL::del(node *temp)
{
    if(start==NULL || temp==NULL)
    {
        cout<<"Deleteion cannot be performed";
    }
    else
    {
        if(start==temp)
        {
            deleteFirst();
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
    }
}
