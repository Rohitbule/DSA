#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque <int> d1={10,35,22,18,70};
    for(int i=0;i<d1.size();i++)
        cout<<d1[i]<<" ";
    cout<<endl;
    for(int i=0;i<d1.size();i++)
        cout<<d1.at(i)<<" ";   
    cout<<endl;
    for(auto x:d1)
        cout<<x<<" ";
    cout<<endl;
    deque<int>::iterator it;
    for(it=d1.begin();it!=d1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    deque<int>d2;
    
    d2.assign({11,22,33});
    d2.push_front(44);
    d2.emplace_front(66);
    d2.push_back(55);
    d2.emplace_back(77);
    cout<<d2.empty()<<endl;
    cout<<d2.back()<<endl;
    cout<<d2.front()<<endl;
    d2.insert(d2.begin()+2,100);
    d2.erase(d2.end()-2);
    d2.pop_front();
    d2.pop_back();
    for(auto x:d2)
        cout<<x<<" ";

    cout<<endl;

    return 0;
}