using namespace std;
#include<bits/stdc++.h>
class Graph
{
    int vertex;
    list<int>*l;
public:
    Graph(int v)
    {
        vertex=v;
        l=new list<int>[v];
    }
    // undirected graph:
    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print()
    {
        for(int i=0;i<vertex;++i)
        {
            cout<<i<<" : ";
            for(int neigh:l[i])
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.print();
}