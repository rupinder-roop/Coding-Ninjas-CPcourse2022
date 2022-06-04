#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<int>* graph, int start, bool* visited, stack<int> &s){
	visited[start] = 1;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		if (visited[graph[start].at(i)] == 0)
		{
			dfs1(graph, graph[start].at(i), visited, s);			
		}	
	}

	//Will put in stack in the last
	s.push(start);

	return;
}

void dfs2(vector<int>* graph, int start, bool* visited){
	visited[start] = 1;
	for (int i = 0; i < graph[start].size(); ++i)
	{
		int v = graph[start].at(i);
		if (visited[graph[start].at(i)] == 0)
		{
			dfs2(graph, v, visited);
		}
	}

	return;
}

void kosaraju(vector<int>* graph, vector<int>* grapht, int n){
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	stack<int> s;

	for (int i = 0; i < n; ++i)
	{
		if (visited[i]==0)
		{
			dfs1(graph, i, visited, s);
		}
	}

	//Step 2
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		if (visited[v] == 0)
		{
			count++;
			dfs2(graph, v, visited);
		}
	}

	cout << count << '\n';


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;

		vector<int>* graph = new vector<int>[n];
		vector<int>* grapht = new vector<int>[n];
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin>>u>>v;
			graph[u-1].push_back(v-1);
			grapht[v-1].push_back(u-1);
		}

		kosaraju(graph, grapht, n);

	}


	return 0 ; 



}
