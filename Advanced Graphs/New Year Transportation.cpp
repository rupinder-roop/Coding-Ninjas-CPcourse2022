#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 1 ; i < n ; ++i) {
			cin >> a[i];
		}

		vector<bool> visited(n, false);

		int index = 1;
		while(index < n) {
			visited[index] = true;
			int step = index + a[index];
			index = step;
		}

		int q; cin >> q;
		while(q--) {
			int x; cin >> x;
			if(visited[x] || x == n) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
