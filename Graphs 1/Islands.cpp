# include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    int **adj;

    public:
        Graph(int V);
        void addEdge(int a , int b);
        int BFS();
};

Graph::Graph(int V){
    this->V = V;
    adj = new int*[V];

    for (int i = 0; i < V; i++)
    {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
        
    }
}

void Graph::addEdge(int a,int b){
    adj[a][b] = 1;
    adj[b][a] = 1;
}

void printBFS(int s , int V , int * visited , int **adj){
    queue<int> q;

    q.push(s);
    visited[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // cout<<u<<" ";

        for (int i = 0; i < V; i++)
        {
            if(adj[u][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
        

    }
    cout<<endl;

}

int Graph::BFS(){
    int visited[V] {0};

    int cnt = 0;

    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            cnt++;
            printBFS(i,V,visited,adj);
        }
    }
    

    return cnt;
}

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int n,e;
        cin>>n>>e;

        Graph g(n);

        for (int i = 0; i < e; i++)
        {
            int a,b;
            cin>>a>>b;
            g.addEdge(a,b);
        }

        cout<<g.BFS()<<endl;
        

    }
    

    return 0;
}
