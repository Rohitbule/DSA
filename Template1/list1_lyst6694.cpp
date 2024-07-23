#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>l1={30,60,20,40};
    //How to access list elements
    // [] and at() are not there in list
    //1. Implicit Iterator
    for(auto x:l1)
        cout<<x<<" ";
    cout<<endl;
    //2. Explicit Iterator
    list<int>::iterator it;
    for(it=l1.begin();it!=l1.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<l1.back()<<" "<<l1.front()<<endl;
    l1.reverse();
    for(auto x:l1)
        cout<<x<<" ";
    cout<<endl;
    list<int>l2={2,4,6};
    it=l1.begin();
    it++;
    l1.splice(it,l2);
    for(auto x:l1)
        cout<<x<<" ";
    cout<<endl;
    for(auto x:l2)
        cout<<x<<" ";
    cout<<endl;
    
    return 0;
}