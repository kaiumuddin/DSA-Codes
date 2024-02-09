#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int v;
    int w;
    node(int x,int y)
    {
        v = x;
        w = y;
    }
};

void addV(vector<node> g[], int x, int y, int w)
{
    //for directed graph
    //node a(y,w);
    g[x].push_back(node(y,w));

    //for undirected graph
    //node b(x,w);
    //g[y].push_back(b);
}

void printG(vector<node> g[], int V)
{
    for(int i=0; i< V; ++i)
    {
        cout<<"Vertex "<<i;
        for(auto j:g[i])
        {
            //cout<<" -> "<< g[i][j].v<<","<<g[i][j].w<<"   ";
            cout<<" -> "<< j.v<<","<<j.w<<"   ";
        }
        cout<<endl;
    }
}

int main()
{
    int V = 5;
    vector<node> g[V];

    addV(g,0,1,10);
    addV(g,0,3,2);
    addV(g,0,2,3);
    addV(g,2,3,6);
    addV(g,1,3,7);

    printG(g,V);


    return 0;

}
