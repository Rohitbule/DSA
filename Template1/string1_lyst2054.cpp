#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1="Dilip";
    string s2;
    cout<<s1<<endl;
    for(int i=0;i<s1.size();i++)
        cout<<s1[i]<<" ";
    cout<<endl;
    for(int i=0;i<s1.size();i++)
        cout<<s1.at(i)<<" ";
    cout<<endl;
    for(auto x:s1)
        cout<<x<<" ";
    cout<<endl;
    string::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<s1.front()<<endl;
    cout<<s1.back()<<endl;
    s1.append(" Souner");
    cout<<s1<<endl;
    s1.insert(6,"Kumar ");
    cout<<s1<<endl;
    s1.replace(6,5,"Singh");
    cout<<s1<<endl;
    cout<<s1.substr(6,5);
    cout<<endl;
    s1=s1+" Ji";
    cout<<s1<<endl;


    return 0;
}