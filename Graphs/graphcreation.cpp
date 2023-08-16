#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph
{
    unordered_map<int, list<int>> adj;
    public:
    void addEdge(int u, int v, bool direction)
    {
        //direction=0 -> undirected graph
        //direction = 1 directed graph

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction==0)
        adj[v].push_back(u);
    }
    void print()
    {
        for(auto i:adj)
        {
            cout<< i.first << " -> ";
            for(auto j:i.second)
            cout<<j<< ",";
            cout<<endl;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter no. of nodes"<< endl;
    cin>>n;

    graph g;
    int m;
    cout<<"Enter no. of edges"<< endl;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.print();
    return 0;
}