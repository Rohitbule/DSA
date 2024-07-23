#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<string>
using namespace std;
class Employee
{
    private:
        int empid;
        string name;
        float salary;
    public:
        Employee(int i,string n,float s):empid(i),name(n),salary(s)
        {}
        float getSalary()
        {
            return salary;
        }
        void showEmployee()
        {
            cout<<empid<<" "<<name<<" "<<salary<<endl;
        }
};
class CompareSalary
{
    public:
        bool operator()(Employee &e1, Employee &e2)
        {
            return e1.getSalary()<e2.getSalary();
        }
};
int main()
{
    priority_queue <int> pq1; //vector
    priority_queue<string,deque<string>> pq2; //deque
    priority_queue <Employee, deque<Employee>,CompareSalary>pq3;
    pq3.push(*(new Employee(1,"Srinjan",30000)));
    pq3.push(*(new Employee(2,"Amit",40000)));
    pq3.push(*(new Employee(3,"Ajay",23000)));
    pq3.push(*(new Employee(4,"Javed",35000)));
    pq3.push(*(new Employee(5,"Dipti",42000)));

    Employee e=pq3.top();
    e.showEmployee();



    pq1.push(20);
    pq1.push(45);
    pq1.push(50);
    pq1.push(15);
    pq1.push(30);
    pq1.pop();
    cout<<pq1.top()<<endl;

    pq2.push("Sandeep");
    pq2.push("Navin");
    pq2.push("Ashika");
    pq2.push("Ranjan");
    cout<<pq2.top()<<endl;
    return 0;
}