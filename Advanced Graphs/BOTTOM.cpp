#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

vector<bool> seen;
stack<int> finishedVertices;

void DFS1(vector<vector<int>>& g, int v) {
	seen[v] = true;
	for(int next : g[v]) {
		if(!seen[next]) DFS1(g, next);
	}
	finishedVertices.push(v);
}

void DFS2(vector<vector<int>>& g, int node, vector<int>& current) {
	seen[node] = true;
	current.push_back(node);
	for(int next : g[node]) {
		if(!seen[next]) DFS2(g, next, current);
	}
}

vector<vector<int>> getSCC(vector<vector<int>>& g, vector<vector<int>>& gt, int& n) {
	seen = vector<bool>(n+1, false);
	finishedVertices = stack<int>();
	for(int i = 1 ; i <= n ; ++i) {
		if(!seen[i]) {
			DFS1(g, i);
		}
	}

	vector<vector<int>> ans;

	seen = vector<bool>(n+1, false);
	while(!finishedVertices.empty()) {
		int node = finishedVertices.top();
		finishedVertices.pop();

		if(!seen[node]) {
			vector<int> current;
			DFS2(gt, node, current);
			ans.push_back(current);
		}
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int m; cin >> m;

		vector<vector<int>> g(n+1), gt(n+1);
		for(int i = 0 ; i < m ; ++i) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			gt[y].push_back(x);
		}

		vector<vector<int>> scc = getSCC(g, gt, n);

		set<int> bottom;

		for(vector<int> component : scc) {
			// for O(1) query
			unordered_set<int> currentComponent;
			for(int node : component) {
				currentComponent.insert(node);
			}
			
			bool flag = true;
			for(int node : currentComponent) {
				for(int neighbor : g[node]) {
					if(!currentComponent.count(neighbor)) {
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}

			if(flag) {
				for(int node : currentComponent) {
					bottom.insert(node);
				}
			}
		}

		for(int x : bottom) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}
