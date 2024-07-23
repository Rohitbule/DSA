#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
int main()
{
    map<int,string>m1={
        {1,"Bhopal"},
        {2,"Indore"},
        {3,"Jabalpur"},
        {4,"Ujjain"},
        {5,"Gwalior"}  
    };
    for(auto e:m1)
    {
        cout<<e.first<<"  "<<e.second<<endl;
    }
    map<int,string>::iterator it;
    for(it=m1.begin();it!=m1.end();it++)
        cout<<it->first<<" "<<it->second<<endl;

    cout<<m1.at(3)<<endl;
    cout<<m1.count(5)<<endl;
    
    pair<int,string> p1={6,"Sagar"};
    m1.emplace(p1);
    for(auto e:m1)
    {
        cout<<e.first<<"  "<<e.second<<endl;
    }
    m1.erase(m1.begin());
     for(auto e:m1)
    {
        cout<<e.first<<"  "<<e.second<<endl;
    }
    return 0;
}