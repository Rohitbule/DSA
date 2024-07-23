#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
void example1() //adjacent_find()
{
    vector<int>v1={10,4,5,13,7,4,21,15,11,11,11,21};
    int x=*adjacent_find(v1.begin(),v1.end());
    cout<<"Pair found with element value="<<x;
    vector<int>v2={10,3,10,5,11,34,21};
    vector<int>::iterator it;
    it=adjacent_find(v2.begin(),v2.end());
    if(it==v2.end())
        cout<<"\nNo such pair found";

}
void example2() //all_of()
{
    vector<int>v1={10,20,14,50,18,6,12};
    if(all_of(v1.begin(),v1.end(),[](int a)->bool {return a%2==0;}))
        cout<<"\nAll numbers are even";
    else
        cout<<"\nAll numbers are not even";
}
void example3() //any_of()
{
    vector<int>v1={10,20,14,50,18,6,12};
    if(any_of(v1.begin(),v1.end(),[](int a)->bool { return a%2==1;}))
        cout<<"\nAt least one element is Odd";
    else
        cout<<"\nNone of the elements is Odd";
}
void example4() //binary search
{
    vector<int> v1={1,4,4,6,7,7,21,53,112,117,119,200};
    if(binary_search(v1.begin(),v1.end(),112))
        cout<<"Element Found";
    else
        cout<<"Element not found";
}
void example5() //lower_bound() and upper_bound()
{
    vector<int>v1={1,4,4,6,7,7,21,53,112,117,119,200};
    vector<int>::iterator it;
    it=lower_bound(v1.begin(),v1.end(),7);
    cout<<"\nElement just greater than or equal to 7 is at index: "<<it-v1.begin();
    it=upper_bound(v1.begin(),v1.end(),7);
    cout<<"\nElement just greater than 7 is at index: "<<it-v1.begin();

}
void example6() //max_element() and min_element()
{
    vector<int>v1={1,4,4,6,7,7,21,53,112,117,119,200};
    cout<<"\nMax element: "<<*max_element(v1.begin(),v1.end()-4);
    cout<<"\nMin Element: "<<*min_element(v1.begin(),v1.end());
}
void example7() //for_each()
{
    vector<int>v1={1,4,4,6,7,7,21,53,112,117,119,200};
    for_each(v1.begin(),v1.end(),[](int x)->void {cout<<endl<<x<<" - "<<x*x;});
}
void example8() //generate()
{
    vector<int>v1(10);
    generate(v1.begin(),v1.end(),[]()->int {static int i;++i; return i*i;});
    for(int num:v1)
        cout<<num<<" ";
}
void example9() //generate_n()
{
    vector <int> v1(10);
    generate_n(v1.begin(),5,[]()->int {static int i; ++i; return i*i;});
    generate_n(v1.begin()+5,5,[]()->int {static int j;++j;return j*j*j;});
    for(int num:v1)
        cout<<num<<" ";
}
void example10() //count() and count_if()
{
    vector<int> v1={21,4,4,6,7,7,121,53,110,4,19,20};
    cout<<count(v1.begin(),v1.end(),14)<<endl;
    cout<<count_if(v1.begin(),v1.end(),[](int x)->bool { return x>15;});
}
void example11() //find()
{
    vector<int> v1={21,4,4,6,7,7,121,53,110,4,19,20};
    vector<int>::iterator it;
    it=find(v1.begin(),v1.end(),110);
    if(it==v1.end())
        cout<<"Element not found";
    else
        cout<<"Element found at index "<<it-v1.begin();
}
void example12() //find_if()
{
    vector<int> v1={21,5,5,6,7,7,121,53,110,4,19,20};
    vector<int>::iterator it;
    it=find_if(v1.begin(),v1.end(),[](int x)->bool {
        int k;
        k=(int)sqrt(x);
        return k*k==x;
    });
    if(it==v1.end())
        cout<<"Element not found";
    else
        cout<<"Element "<<*it<<" found at index "<<it-v1.begin();
}
void example13() //equal()
{
    vector<int>v1={1,2,3,4,5,6};
    vector<int>v2={2,3,4};
    if(equal(v2.begin(),v2.end(),v1.begin()+1))
        cout<<"Equal";
    else
        cout<<"Not equal";
}
void example14() //fill()
{
    vector<int>v1={10,10,20,30,30,40,40,40,50,60,60,70,70,70,80};
    fill(v1.begin()+1,v1.begin()+5,100);
    for( auto num:v1)
        cout<<num<<" ";
}
void example15() //remove()
{
    vector<int>v1={11,2,5,11,18,25};
    vector<int>::iterator it,newEnd;
    newEnd=remove(v1.begin(),v1.end(),11);
    for(auto num:v1)
        cout<<num<<" ";
    cout<<endl;
    for(it=v1.begin();it!=newEnd;it++)
        cout<<*it<<" ";
}
void example16() //reverse()
{
    vector<int>v1={11,2,5,11,18,25};
    reverse(v1.begin(),v1.end());
    for(int num:v1)
        cout<<num<<" ";
}
void example17() //replace()
{
    vector<int>v1={10,3,4,4,4,5,5,77};
    replace(v1.begin(),v1.end(),4,63);
    for(auto num:v1)
        cout<<num<<" ";
}
void example18() //search()
{
    vector<int>v1={11,44,22,77,33,99,66,55,88};
    vector<int>v2={99,66,55};
    vector<int>::iterator it;

    it=search(v1.begin(),v1.end(),v2.begin(),v2.end());
    if(it!=v1.end())
        cout<<"Subsequence found at index "<<it-v1.begin();
    else
        cout<<"Subsequence not found";
}
void example19() //is_sorted()
{
    vector<int>v1={11,14,22,25,33,33,33,55,88};
    if(is_sorted(v1.begin(),v1.end()))
        cout<<"Yest it is sorted";
    else
        cout<<"No it is not sorted";
}
void example20() //is_sorted_until()
{
    vector <int>v1={11,14,22,77,33,33,44,55};
    vector<int>::iterator it;
    it=is_sorted_until(v1.begin(),v1.end());
    cout<<*it<<endl;
    cout<<"Number of elements sorted until the first unsorted one is"<<it-v1.begin();
}
int main()
{
    example20();
    cout<<endl;
    return 0;
}