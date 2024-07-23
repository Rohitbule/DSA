#include<iostream>
#include<array>
using namespace std;
void p1()
{
    array <int,5> a1={10,20,30,40,50};
    array<int,5>::reverse_iterator rit;
    for(rit=a1.rbegin();rit!=a1.rend();rit++)
        cout<<*rit<<" ";
    cout<<endl;
}
void p2()
{
    array <float,5> a1={2.5f,7.3f,5.6f,1.04f,3.0f};
    array<float,5>::iterator it;
    float avg,sum=0;
    for(it=a1.begin();it!=a1.end();it++)
        sum=sum+*it;
    avg=sum/a1.size();
    cout<<"Average is "<<avg;
    cout<<endl;
}
void p3()
{
    int temp;
    array <int,10> a1;
    cout<<"Enter 10 numbers: ";
    for(int i=0;i<=9;i++)
    {   
        cin>>temp;
        a1[i]=temp;
    }
    cout<<"Greatest element is "<<*max_element(a1.begin(),a1.end());
    cout<<endl;
}
class Complex
{
    private:
        int a,b;
    public:
        Complex(int x,int y):a(x),b(y)
        {}
        void showData(){ 
            cout<<"\na="<<a<<" b="<<b;
        }
        Complex operator+ (Complex C)
        {
            Complex temp(0,0);
            temp.a=a+C.a;
            temp.b=b+C.b;
            return temp;
        }
};
void p4()
{
    Complex sumComplex(array<Complex,5>);
    array <Complex,5> a1={
                            Complex(2,3),
                            Complex(-4,7),
                            Complex(1,-2),
                            Complex(8,0),
                            Complex(4,4)
                            };
    Complex C=sumComplex(a1);
    C.showData();
    cout<<endl;
}
Complex sumComplex(array<Complex,5> a1)
{
    Complex C(0,0);

    for(auto x:a1)
        C=C+x;
    return C;
}

void p5()
{
    array <int,10> a1={29,60,92,48,77,16,8,36,52,83};
    sort(a1.begin(),a1.end());
    for(auto x:a1)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
    p5();
    cout<<endl;
    return 0;
}