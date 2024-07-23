#include<iostream>
#include<vector>
using namespace std;

vector<int> p1(vector<int> v1)
{
    v1.erase(find_if(v1.begin(),v1.end(),[](int x) -> bool {return x<0;}),v1.end());
    return v1;
}
void p2()
{
    vector <int> v1 = {20,60,30};
    v1.insert(v1.end()-1,3,25);
    for(auto x : v1)
        cout<<x<<" ";
    cout<<endl;
}
void p3()
{
    vector<int> given_vector = {2,4,10,5,7,6,15,20,3,9};
    vector <vector<int>> v1;
    vector <int> *ptr;
    int i=0,s,e,j=0;
    while(i<given_vector.size()-1)
    {
        s=i;
        while(i<given_vector.size()-1 && given_vector.at(i)<given_vector.at(i+1))
            i++;
        e=++i;
        ptr=new vector<int>();
        ptr->insert(ptr->begin(),given_vector.begin()+s,given_vector.begin()+e);
        v1.insert(v1.begin()+j,*ptr);
        j++;
        
    }
    for(auto x : v1)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}
bool is_prime(int x)
{
    int i;
    for(i=2;i<=x-1;i++)
        if(x%i==0)
            return false;
    return true;
}
void p4()
{
    vector <int>v1={2,10,7,14,23,18,53};
    /*
    int i;
    for(i=0;i<v1.size();i++)
    {
        if(is_prime(v1.at(i)))
        {
            v1.erase(v1.begin()+i);
            i--;
        }
    }
    for(auto x : v1)
        cout<<x<<" ";
    cout<<endl;
    */
    
    vector<int>::iterator newEnd,it;
    newEnd=remove_if(v1.begin(),v1.end(),[](int x)->bool { return is_prime(x);});
    for(it=v1.begin();it!=newEnd;it++)
        cout<<*it<<" ";
    cout<<endl;
}
void p5()
{
    vector <vector<int>> vec={
        {1,2,3,4,5},
        {10,20,30,40,50},
        {100,200,300,400,500}
    };
    vector <int> v1;
    v1.insert(v1.end(),vec.at(0).begin(),vec.at(0).begin()+3);
    v1.insert(v1.end(),vec.at(1).end()-2,vec.at(1).end());
    v1.insert(v1.end(),vec.at(2).begin(),vec.at(2).end());
    for(auto x : v1)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
   
/*
    vector <int> v1={10,60,30,-40,70,-10,20};
    for(auto x : p1(v1))
        cout<<x<<" ";
*/    
    p5();
    cout<<endl;
    return 0;
}
