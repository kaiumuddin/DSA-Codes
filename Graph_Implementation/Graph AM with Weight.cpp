#include<bits/stdc++.h>
using namespace std;

const int V = 7;

void addEdge(array<array<int,V>, V> &adj, int x, int y, int w)
{
    adj[x][y] = w;
    adj[y][x] = w;
}
void printGraph(array<array<int,V>, V> &adj)
{
    int w = 2;
    cout<<setw(w)<<"*";
    for(int v=0; v<V; v++)
        cout<<setw(w)<<v<<" ";

    cout<<endl;

    for(int i=0; i<V; i++)
    {
        cout<<setw(w)<<i;
        for(int j=0; j<V; j++)
        {
            cout<< setw(w)<< adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void BFS(array<array<int,V>, V> &adj, int s)
{
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.front();
        cout<< s <<" ";
        queue.pop_front();

        for(int j=0; j<V; j++)
        {
            if(adj[s][j] == 1 && visited[j]== false)
            {
                visited[j] = true;
                queue.push_back(j);
            }
        }
    }

    cout<<endl;
}

int main()
{
    array<array<int,V>, V> adj;

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            adj[i][j] = 0;

    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 3, 1);
    addEdge(adj, 1, 0, 1);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 1, 5, 1);
    addEdge(adj, 2, 1, 1);
    addEdge(adj, 2, 3, 1);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 2, 5, 1);
    addEdge(adj, 3, 0, 1);
    addEdge(adj, 3, 1, 1);
    addEdge(adj, 3, 2, 1);
    addEdge(adj, 3, 4, 1);
    addEdge(adj, 4, 2, 1);
    addEdge(adj, 4, 3, 1);
    addEdge(adj, 4, 6, 1);
    addEdge(adj, 5, 1, 1);
    addEdge(adj, 5, 2, 1);
    addEdge(adj, 6, 1, 1);
    addEdge(adj, 6, 4, 1);

    printGraph(adj);
    BFS(adj, 0);
    BFS(adj, 1);
    BFS(adj, 2);
    BFS(adj, 3);
    BFS(adj, 4);
    BFS(adj, 5);
    BFS(adj, 6);
}
