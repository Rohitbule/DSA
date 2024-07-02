#include<iostream>
#include<stdio.h>
#include "DynArray.cpp"
using namespace std;
class GraphMatrix
{
    private:
        int v_count;
        int e_count;
        int **adj;
    public:
        int getVCount();
        void createGraph(int vno,int eno);
        void printMatrix();
        void printAdjacentNodes(int);
        DynArray& adjacentNodes(int);
        bool isIsolated(int);
        ~GraphMatrix();
        
};
DynArray& GraphMatrix::adjacentNodes(int n)
{
    DynArray *p=new DynArray(1);
    if(n<v_count && n>=0)
    {
        for(int i=0;i<v_count;i++)
            if(adj[n][i]==1)
                p->append(i);

    }
    return *p;
}
int GraphMatrix::getVCount()
{
    return v_count;
}
GraphMatrix::~GraphMatrix()
{
    for(int i=0;i<v_count;i++)
        delete []adj[i];
    delete []adj;
}
bool GraphMatrix::isIsolated(int v)
{
    bool flag=true;
    if(v<v_count && v>=0)
    {
        for(int i=0;i<v_count;i++)
            if(adj[v][i]==1)
            {
                flag=false;
                break;
            }   
    }
    return flag;
}
void GraphMatrix::printAdjacentNodes(int v)
{
    if(v<v_count && v>=0)
    {
        for(int i=0;i<v_count;i++)
            if(adj[v][i]==1)
                cout<<endl<<"V"<<i;

    }
}
void GraphMatrix::printMatrix()
{
    cout<<endl;
    for(int i=0;i<v_count;i++)
    {
        for(int j=0;j<v_count;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
void GraphMatrix::createGraph(int vno,int eno)
{
    int u,v;
    v_count=vno;
    e_count=eno;
    adj=new int*[v_count];
    for(int i=0;i<v_count;i++)
        adj[i]=new int[v_count];
    
    for(int i=0;i<v_count;i++)
        for(int j=0;j<v_count;j++)
            adj[i][j]=0;
    for(int k=1;k<=e_count;k++)
    {
        cout<<"\nEnter node numbers connecting edge:";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}
int main()
{
    GraphMatrix G;
    G.createGraph(5,6);
    G.printMatrix();
    G.printAdjacentNodes(2);
    cout<<endl;
    return 0;
}
