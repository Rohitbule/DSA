#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<list>
using namespace std;
int main()
{
    queue<int,list<int>> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.pop();
    cout<<q1.front()<<endl;
    cout<<q1.back();
    cout<<endl;
    return 0;
}