#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;
int main()
{
    stack<int>s1; //deque
    stack<int,vector<int>> s2; //vector
    stack<int,list<int>> s3; //list
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;
    s1.pop();
    cout<<s1.top();
    cout<<endl;
    
    
    return 0;
}