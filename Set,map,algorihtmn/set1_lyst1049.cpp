#include<iostream>
#include<set>
#include<string>
using namespace std;
class Book
{
    private:
        int bookid;
        string title;
        float price;
    public:
        int getBookid() const { return bookid;}
        float getPrice() const { return price;}
        Book(int i,string t,float p):bookid(i),title(t),price(p)
        {}
        void showBook() const
        {
            cout<<bookid<<" "<<title<<" "<<price<<endl;
        }
};
class OrderByBookId
{
    public:
        bool operator()(const Book &b1,const Book &b2) const
        {
            if(b1.getBookid()<b2.getBookid())
                return true;
            else
                return false;
        }
};
class OrderByPrice
{
    public:
        bool operator()(const Book &b1,const Book &b2) const
        {
            if(b1.getPrice()<b2.getPrice())
                return true;
            else
                return false;
        }
};
class desc
{
    public:
        bool operator()(const int &a,const int &b) const
        {
             if(a>b)
                return true;
            else
                return false;
        }
};
int main()
{
    set <int,desc>s1={10,30,10,20,50,40};
    set<Book,OrderByPrice>s2={*new Book(1,"Java",340.0),
                *new Book(2,"Python",405.0),
                *new Book(3,"CPP",275.0),
                *new Book(4,"Django",805.0)
                };
    for(auto x:s2)
        x.showBook();
    cout<<endl;
    set<Book,OrderByPrice>::iterator it;
    for(it=s2.begin();it!=s2.end();it++)
        it->showBook();
    cout<<s2.empty()<<endl;
    cout<<s1.count(10)<<endl;
    s1.emplace(70);
    for(auto x:s1)
        cout<<x<<" ";
    cout<<endl;
    set<int,desc>::iterator it1=s1.begin();
    set<int,desc>::iterator it2=s1.end();
    it1++;
    it2--;
    s1.erase(it1,it2);
    for(auto x:s1)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}