#include<iostream>
#include "Item.cpp"
using namespace std;

template <typename X>
X big(X a,X b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    cout<<big(34,56)<<endl;
    cout<<big(5.4,1.2)<<endl;
    Item i1,i2;
    i1.setData(3,4);
    i2.setData(5,1);
    (big(i1,i2)).showData();
    cout<<endl;
    return 0;

}


