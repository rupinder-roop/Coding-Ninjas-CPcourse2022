#include <bits/stdc++.h>

using namespace std;

void dfs(long long sv, vector<long long>* graph, long long n, bool* isVisited, unordered_set<long long>* component){
	
	isVisited[sv] = 1;

	component->insert(sv);
	for (long long i = 0; i < graph[sv].size() ; ++i)
	{
		if (isVisited[graph[sv][i]] == 0)
		{
			dfs(graph[sv][i], graph, n, isVisited, component);
		}
	}

	return;
}

unordered_set<unordered_set<long long>*>* connect(vector<long long>* graph, long long n){
	
	unordered_set<unordered_set<long long>*>* ans = new unordered_set<unordered_set<long long>*>();

	bool* isVisited = new bool[n];
	for (long long i = 0; i < n; ++i)
	{
		isVisited[i] = 0;
	}

	for (long long i = 0; i < n; ++i)
	{
		if (isVisited[i] == 0)
		{
			unordered_set<long long>* component = new unordered_set<long long>();
			dfs(i, graph, n, isVisited, component);
			ans->insert(component);
		}
	}

	return ans;

	
}

long long go(vector<long long>* graph, long long* arr, long long n){
	unordered_set<unordered_set<long long>*>* components = connect(graph, n);

	long long ans = INT_MIN;

	auto it1 = components->begin();
	while(it1!=components->end()){
		auto it2 = (*it1)->begin();
		long long temp = 0;
		while(it2!=(*it1)->end()){
			temp+=arr[*it2];
			it2++;
		}
		ans = max(temp, ans);
		it1++;
	}

	return ans;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	long long t;
	cin>>t;
	while(t--){
		long long n, m;
		cin>>n>>m;

		vector<long long>* graph =  new vector<long long>[n];
		for (long long i = 0; i < m; ++i)
		{
			long long a, b;
			cin>>a>>b;
			graph[a-1].push_back(b-1);
			graph[b-1].push_back(a-1);
		}

		long long* arr = new long long[n];
		for (long long i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}

		cout << go(graph, arr, n) << '\n';
	}



	return 0 ; 



}
