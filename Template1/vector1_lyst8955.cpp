#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> v1={25,67,31,10,54,32};
    vector<string> v2={"Bhopal","Patna","Kanpur","Ujjain"};
    //How to access vector elements?
    //1. []
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    //2. at()
    for(int i=0;i<v1.size();i++)
        cout<<v1.at(i)<<" ";
    cout<<endl;
    //3. implicit iterator
    for(auto x:v2)
        cout<<x<<" ";
    cout<<endl;
    //4. Explicit Iterator
    vector<string>::iterator it;
    for(it=v2.begin();it!=v2.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<"back  "<<v2.back()<<endl;
    cout<<"front  "<<v2.front()<<endl;
    cout<<"Vector v2 is empty- "<<v2.empty()<<endl;

    vector <int>v3={10,40,20,50,30};
    v1.swap(v3);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    for(auto x:v3)
        cout<<x<<" ";
    cout<<endl;
    v1.clear();
    cout<<"Size is "<<v1.size()<<endl;
    cout<<"Capacity "<<v1.capacity()<<endl;
    //Ways to insert data in vector
    //1. push_back()
    v1.push_back(60);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    //2. insert()
    v1.insert(v1.begin()+1,{30,80,90});
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    //3. emplace_back()
    v1.emplace_back(100);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    //4. emplace()
    v1.emplace(v1.begin()+2,200);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Capacity - "<<v1.capacity()<<endl;
    *(v1.begin()+2)=150;
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    v1.shrink_to_fit();
    cout<<"Capacity - "<<v1.capacity()<<endl;

    v1.insert(v1.begin()+1,4,12);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;

    v1.insert(v1.end()-1,v3.begin()+1,v3.begin()+4);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;

    //How to delete elements?
    //1. erase()
    v1.erase(v1.begin()+5);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    //2. erase()
    v1.erase(v1.begin()+3,v1.begin()+8);
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    //3. pop_back()
    v1.pop_back();
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}