#include<iostream>
#include<array>
using namespace std;
int main()
{
    array <int,4>a1={10,50,30,40};
    array <string,3>a2={"Bhopal","Pune","Jaipur"};

    //How to access array elements?
    //1. using []
    for (int i=0;i<5;i++)
        cout<<a1[i]<<" ";
    cout<<endl;
    //2. using at()
    try{
    for (int i=0;i<5;i++)
        cout<<a1.at(i)<<" ";
    cout<<endl;
    }
    catch(std::out_of_range e){
        cout<<"Array out of Index Exception"<<endl;
    }
    //3. using implitic iterator | using range-for loop
    for(auto x:a1)
        cout<<x<<" ";
    cout<<endl;
    //4. using explicit iterator
    array<int,4>::iterator i1;
    for(i1=a1.begin();i1!=a1.end();i1++)
    {
        cout<<*i1<<" ";
    }
    cout<<endl;
    array<int,4>::reverse_iterator i2;
    for(i2=a1.rbegin();i2!=a1.rend();i2++)
    {
        cout<<*i2<<" ";
    }
    cout<<endl;

    array<int,4>::const_iterator i3;
    i3=a1.cbegin();
    *(a1.begin()+2)=70;
    cout<<*(i3+2)<<endl;
    cout<<a1.back()<<endl;
    cout<<a1.front()<<endl;
    cout<<a1.size()<<endl;
    
    return 0;

}