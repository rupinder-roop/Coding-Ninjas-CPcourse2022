#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf (int)1e9
#define f first
#define s second

class DSU {
private:
	vector<int> parent, rank;

public:
	DSU(int n) {
		for(int i = 0 ; i < n ; ++i) {
			rank.push_back(0);
			parent.push_back(i);
		}
	}

	int get_set(int x) {
		if(parent[x] == x) return x;
		return parent[x] = get_set(parent[x]);
	}

	void union_set(int x, int y) {
		x = get_set(x);
		y = get_set(y);
		if(x != y) {
			if(rank[x] == rank[y]) ++rank[x];
			if(rank[x] < rank[y]) swap(x, y);
			parent[y] = x;
		}
	}
};

class edge {
public:
	int src, dst, val;

	edge(int s, int d, int v) {
		src = s;
		dst = d;
		val = v;
	}
};

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int Case = 1;
	int t; cin >> t;
	while(t--)
	{
		int n, m, airportCost;
		cin >> n >> m >> airportCost;

		vector<edge> graph;
		for(int i = 0 ; i < m ; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			graph.push_back(edge(x-1, y-1, z));
		}

		sort(graph.begin(), graph.end(), [&](edge a, edge b) {
			return a.val < b.val;
		});

		DSU dsu(n);

		int total = 0, airportsCount = 0;

		int index = 0, count = 0;
		while(index < m && count < n-1 && graph[index].val < airportCost) {
			edge x = graph[index];
			if(dsu.get_set(x.src) != dsu.get_set(x.dst)) {
				dsu.union_set(x.src, x.dst);
				total += x.val;
				++count;
			}
			++index;
		}

		for(int i = 0 ; i < n ; ++i) {
			if(dsu.get_set(i) == i) {
				total += airportCost;
				++airportsCount;
			}
		}

		cout << total << '\n';
	}
	return 0;
}
