#include<iostream>
using namespace std;
class graph
{
    int v;
    int **adj;
    public:
    graph(int v)
    {
        this->v=v;
        adj=new int*[v];
        for(int r=0;r<v;r++){
        adj[r]=new int[v];
        for(int c=0;c<v;c++)
            adj[r][c]=0;
        }
    }
    void addedge(int s,int e){
        adj[s][e]=1;
        adj[e][s]=1;
    }
    void print(){
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(0,2);
    g.addedge(0,3);
    g.print();
    return 0;
}