#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	ll value, ind;
};
bool comp(node n1, node n2) {
	return n1.value < n2.value;
}
void buildtree(node *tree, ll *arr, ll s, ll e, ll i) {
	if (s == e) {
		tree[i].value = arr[s];
		tree[i].ind = -s;
		return;
	}

	ll mid = (s + e) / 2;
	buildtree(tree, arr, s, mid, 2 * i);
	buildtree(tree, arr, mid + 1, e, 2 * i + 1);
	tree[i] = max(tree[2 * i], tree[2 * i + 1], comp);
}

node query(node *tree, ll s, ll e, ll i, ll l, ll r, ll n) {
	if (s > r || e < l) {
		return {0, -n};
	}
	if (s >= l && e <= r) {
		return tree[i];
	}
	ll mid = (s + e) / 2;
	node ans1 = query(tree, s, mid, 2 * i, l, r, n);
	node ans2 = query(tree, mid + 1, e, 2 * i + 1, l, r, n);
	return max(ans1, ans2, comp);
}

int main() {
	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 1; i < n; i++) {
		cin >> arr[i];
	}
	node tree[4 * n];
	ll dp[n + 1] = {0};
	buildtree(tree, arr, 1, n, 1);

	ll res = 0;
	for (ll i = n - 1; i >= 1; i--) {
		node ans = query(tree, 1, n, 1, i + 1, arr[i], n);
		ans.ind *= -1;
		dp[i] = (n - i) - (arr[i] - ans.ind) + dp[ans.ind];
		res += dp[i];

	}

	cout << res << endl;
}
