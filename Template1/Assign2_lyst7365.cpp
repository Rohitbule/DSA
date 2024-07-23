#include<iostream>
#include<stdio.h>
using namespace std;
/* Start: Array */
/*
template <typename X>
class Array
{
    private:
        int capacity;
        int lastIndex;
        X *ptr;
    public:
        Array(int);
        Array(Array<X> &);
        bool isEmpty();
        void append(X);
        void insert(int,X);
        void edit(int,X);
        void del(int);
        bool isFull();
        X get(int);
        int count();
        int find(X);
        ~Array();
        int getCapacity();
        void operator=(Array &);

};
template <typename X>void Array<X>::operator=(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];

}
template <typename X>int Array<X>::getCapacity()
{
    return capacity;
}
template <typename X>Array<X>::Array(Array<X> &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
template <typename X>int Array<X>::find(X data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
template <typename X>Array<X>::~Array()
{
    delete[]ptr;
}
template <typename X>int Array<X>::count()
{
    return lastIndex+1;
}
template <typename X>X Array<X>::get(int index)
{
    if(index>=0 && index<=lastIndex)
        return ptr[index];
    cout<<endl<<"Invalid index or empty array";
    throw 1;
}
template <typename X>bool Array<X>::isFull()
{
    return lastIndex==capacity-1;
}
template <typename X>void Array<X>::del(int index)
{
    int i;
    if(isEmpty())
        cout<<endl<<"Array is empty";
    else if(index<0 || index>lastIndex)
        cout<<endl<<"Invalid Index";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    
}
template <typename X>void Array<X>::edit(int index,X data)
{
    if(index>=0&&index<=lastIndex)
        ptr[index]=data;
}
template <typename X>void Array<X>::insert(int index,X data)
{
    int i;
    if(lastIndex==capacity-1)
        cout<<endl<<"Array is already full";
    else if(index<0 || index>lastIndex+1)
    {
        cout<<"Invalid Index";
    }
    else
    {
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
template <typename X>void Array<X>::append(X data)
{
    if(lastIndex==capacity-1)
        cout<<endl<<"Array is already full";
    else
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
template <typename X>bool Array<X>::isEmpty()
{
    return lastIndex==-1;
}
template <typename X>Array<X>::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new X[capacity];

}
*/
/* End: Array */
/* Start: Dynamic Array */
/*
template <typename X>
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        X *ptr;
    public:
        DynArray(int);
        bool isEmpty();
        void append(X);
        void insert(int,X);
        void edit(int,X);
        void del(int);
        bool isFull();
        X get(int);
        int count();
        int find(X);
        void doubleArray();
        void halfArray();
        int size();
        ~DynArray();

};
template <typename X>void DynArray<X>::del(int index)
{
    int i;
    if(isEmpty())
        cout<<endl<<"Array is empty";
    else if(index<0 || index>lastIndex)
        cout<<endl<<"Invalid Index";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if(capacity/2>=lastIndex+1 && capacity>1)
            halfArray();
    }
    
}
template <typename X>void DynArray<X>::insert(int index,X data)
{
    int i;
    if(index<0 || index>lastIndex+1)
        cout<<endl<<"Invalid Index";
    else
    {
        if(isFull())
            doubleArray();
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
template <typename X>void DynArray<X>::append(X data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
template <typename X>int DynArray<X>::size()
{
    return capacity;
}
template <typename X>void DynArray<X>::halfArray()
{
    int *temp=new X[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
template <typename X>void DynArray<X>::doubleArray()
{
    int *temp=new X[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
template <typename X>DynArray<X>::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new X[capacity];

}
template <typename X>bool DynArray<X>::isEmpty()
{
    return lastIndex==-1;
}
template <typename X>void DynArray<X>::edit(int index,X data)
{
    if(index>=0&&index<=lastIndex)
        ptr[index]=data;
}
template <typename X>bool DynArray<X>::isFull()
{
    return lastIndex==capacity-1;
}
template <typename X>X DynArray<X>::get(int index)
{
    if(index>=0 && index<=lastIndex)
        return ptr[index];
    cout<<endl<<"Invalid index or empty array";
    throw 1;
}
template <typename X>int DynArray<X>::count()
{
    return lastIndex+1;
}
template <typename X>DynArray<X>::~DynArray()
{
    delete[]ptr;
}
template <typename X>int DynArray<X>::find(X data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
*/
/* End: Dynamic Array */

/* Start: Linked List */
/*
template <typename X>
struct node
{
    X item;
    node *next;
};
template <typename X>
class SLL
{
    private:
        node *start;
    public:
        SLL();
        void insertAtStart(X);
        void insertAtLast(X);
        node* search(X);
        void insertAfter(node *,X);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~SLL();
        node *getFirstNode();
};
template <typename X>node* SLL<X>::getFirstNode()
{
    return start;
}
template <typename X>SLL<X>::~SLL()
{
    while(start)
        deleteFirst();
}
template <typename X>void SLL<X>::deleteNode(node *temp)
{
    node *t;
    if(start==NULL)
        cout<<"\nUnderflow";
    else 
    {
        if(temp)
        {
            if(start==temp)
            {
                start=temp->next;
                delete temp;
            }
            else
            {
                t=start;
                while(t->next!=temp)
                    t=t->next;
                t->next=temp->next;
                delete temp;                
            }
        }
    }

}
template <typename X>void SLL<X>::deleteLast()
{
    node *t;
    if(start==NULL)
    {
        cout<<"\nUnderflow";
    }
    else if(start->next==NULL)
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
template <typename X>void SLL<X>::deleteFirst()
{
    node *t;
    if(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
template <typename X>void SLL<X>::insertAfter(node *ptr,X data)
{
    node *n=new node;
    n->item=data;
    n->next=ptr->next;
    ptr->next=n;
}
template <typename X>node* SLL<X>::search(X data)
{
    node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
template <typename X>void SLL<X>::insertAtLast(X data)
{
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
     
     while(t->next!=NULL)
        t=t->next;
     t->next=n;
    }
}
template <typename X>void SLL<X>::insertAtStart(X data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
template <typename X>SLL::SLL()
{
    start=NULL;
}
*/
/* End: Linked List */

/* Start: Doubly Linked List */
/*
template <typename X>
struct node
{
    node *prev;
    X item;
    node *next;
};
template <typename X>
class DLL
{
    private:
        node *start;
    public:
        DLL();
        void insertAtStart(X);
        void insertAtLast(X);
        node* search(X);
        void insertAfter(node*,X);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~DLL();
};
template <typename X>DLL<X>::DLL() { start=NULL;}
template <typename X>DLL<X>::~DLL()
{
    while(start)
        deleteFirst();
}
template <typename X>void DLL<X>::deleteNode(node* temp)
{
    if(temp->prev)
        temp->prev->next=temp->next;
    else
        start=temp->next;
    if(temp->next)
        temp->next->prev=temp->prev;
    delete temp;
}
template <typename X>void DLL<X>::deleteLast()
{
    if(start)
    {
        node *t;
        t=start;
        while(t->next!=NULL)
            t=t->next;
        if(t->prev)
            t->prev->next=NULL;
        else
            start=NULL;
        delete t;
    }
}
template <typename X>void DLL<X>::deleteFirst()
{
    if(start)
    {
        node *r=start;
        start=start->next;
        if(r->next)
            start->prev=NULL;
        delete r;
    }
}
template <typename X>void DLL<X>::insertAfter(node* temp,X data)
{
    if(temp)
    {
        node *n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        if(temp->next)
            temp->next->prev=n;
        temp->next=n;
    }
}
template <typename X>node* DLL<X>::search(X data)
{
    node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
template <typename X>void DLL<X>::insertAtLast(X data)
{
    node *t;
    node *n=new node;
    n->next=NULL;
    n->item=data;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }

}
template <typename X>void DLL<X>::insertAtStart(X data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}
*/
/* End: Doubly Linked List */

/* Start: Stack using linked list */
/*

template <typename X>
struct node{
    X item;
    node *next;
};
template <typename X>
class Stack{
    private:
        node *top;
    public:
        Stack();
        Stack(Stack<X>&);
        void push(X);
        bool isEmpty();
        X peek();
        void pop();
        ~Stack();
        void reverse();
        Stack<X>& operator=(Stack<X> &S);
};
template <typename X>Stack<X>& Stack<X>::operator=(Stack<X> &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
    return *this;
}
template <typename X>Stack<X>::Stack(Stack<X> &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}
template <typename X>void Stack<X>::reverse()
{
    node *t1,*t2;
    if(top && top->next)
    {
        t2=NULL;
        do
        {
            t1=top;
            top=top->next;
            t1->next=t2;
            t2=t1;
        } while (top->next!=NULL);
        top->next=t1;
    }
}
template <typename X>Stack<X>::~Stack()
{
    while(top)
        pop();
}
template <typename X>void Stack<X>::pop()
{
    node *r;
    if(isEmpty())
        cout<<"\nStack Underflow";
    else
    {
        r=top;
        top=top->next;
        delete r;
    }
}
template <typename X>X Stack<X>::peek()
{
    if(top==NULL)
    {
        cout<<"\nStack is empty";
        return -1;
    }
    else
        return top->item;
}
template <typename X>bool Stack<X>::isEmpty()
{
    return top==NULL;
}
template <typename X>void Stack<X>::push(X data)
{
    node *n;
    n=new node;
    n->item=data;
    n->next=top;
    top=n;
}
template <typename X>Stack<X>::Stack()
{
    top=NULL;
}
*/
/* End: Stack using linked list */

/* Start: Queue using Arrays */
/*
template <typename X>
class Queue{
    private:
        int capacity;
        int front, rear;
        X* ptr;
    public:
        Queue(int);
        Queue(Queue<X> &);
        void insert(X);
        bool isFull();
        bool isEmpty();
        X getRear();
        X getFront();
        void del();
        ~Queue();
        int count();
        Queue<X>& operator=(Queue<X> &);

};
template <typename X>Queue<X>& Queue<X>:: operator=(Queue<X> &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new X[capacity];
    int n=Q.count();
    int i=Q.front;
    while(n)
    {
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
    return Q;
}
template <typename X>int Queue<X>::count()
{
    if(isEmpty())
        return 0;
    if(front<=rear)
        return rear-front+1;
    return capacity-front+rear+1;
}
template <typename X>Queue<X>::Queue(Queue<X> &Q)
{
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    ptr=new X[capacity];
    int n=Q.count();
    int i=Q.front;
    while(n)
    {
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
}
template <typename X>Queue<X>::~Queue()
{
    delete []ptr;
}
template <typename X>void Queue<X>::del()
{
    if(isEmpty())
        cout<<"\nQueue Underflow";
    else if(front==rear)
        front=rear=-1;
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
template <typename X>X Queue<X>::getFront()
{
    if(!isEmpty())
        return ptr[front];
    cout<<"\nQueue is empty";
    return -1;
}
template <typename X>X Queue<X>::getRear()
{
    if(!isEmpty())
        return ptr[rear];
    cout<<"\nQueue is empty";
    return -1;
}
template <typename X>bool Queue<X>::isEmpty()
{
    return rear==-1;
}
template <typename X>bool Queue<X>::isFull()
{
    return front==0&&rear==capacity-1||rear+1==front;
}
template <typename X>void Queue<X>::insert(X data)
{
    if(isFull())
        cout<<"\nQueue Overflow";
    else if(isEmpty())
    {
        front=rear=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1)
    {
        rear=0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear]=data;
    }
}
template <typename X>Queue<X>::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new X[cap];
}
*/
/* End: Queue using Arrays */
/*
int main()
{
    Array <int> arr(5);
    arr.append(10);
    arr.insert(0,20);
    arr.append(30);
    cout<<arr.get(0);
    cout<<endl;
    return 0;
}
*/