#include <bits/stdc++.h>
using namespace std;
#include <vector>
vector<int> getComponent(vector<int> * edges, bool *visited, int n, int start)
{
    vector<int> ans;
    queue<int> pending;
    pending.push(start);
    visited[start] = true;
    while (!pending.empty())
    {
        int current = pending.front();
        pending.pop();
        ans.push_back(current);
        for (int i = 0; i < edges[current].size(); i++)
        {
            int v = edges[current][i];
            if (!visited[v] && v != start)
            {
                pending.push(v);
                visited[v] = true;
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n, e;
    cin >> n >> e;
    vector<int> edges[n];
        
    for (int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        edges[start].push_back(end);
        edges[end].push_back(start);
    }
    vector<vector<int>> components;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component = getComponent(edges, visited, n, i);
            components.push_back(component);
        }
    }
    if (components.size() != 0)
    {
        for (int i = 0; i < components.size(); i++)
        {
            sort(components[i].begin(), components[i].end());
            for (int j = 0; j < components[i].size(); j++)
            {
                cout << components[i][j]+1 << " ";
            }
            cout << endl;
        }
    }
    }
    return 0;
}
