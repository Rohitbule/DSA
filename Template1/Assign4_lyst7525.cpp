#include<iostream>
#include<vector>
using namespace std;
void q1()
{
    vector<int>v1={20,50,10,30,40,60};
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;

}
void q2()
{
    vector<float>v1={20.4f,50.4f,10.1f,30.6f,40.56f,60.0f};
    for(int i=0;i<v1.size();i++)
        cout<<v1.at(i)<<" ";
    cout<<endl;

}
void q3()
{
    vector<string>v1={"Bhopal","Jaipur","Kanpur","Patna"};
    for(auto x: v1)
        cout<<x<<" ";
    cout<<endl;

}
void q4()
{
    vector<int>v1={20,50,10,30,40,60};
    vector<int>::iterator it;

    for(it=v1.begin();it!=v1.end();it++)
        cout<<*it<<" ";
    cout<<endl;

}
vector<int> q5()
{
    vector<int>v1={20,50,10,30,50,40,60};
    vector <int> v2;
    vector<int>::iterator it;
    for(it=v1.begin()+1;it!=v1.end()-1;it++)
        if(*it < *(it-1) && *it< *(it+1))
            v2.push_back(*it);
    return v2;


}
int main()
{
    vector<int>v2;
    v2=q5();
    for(auto x :v2)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}