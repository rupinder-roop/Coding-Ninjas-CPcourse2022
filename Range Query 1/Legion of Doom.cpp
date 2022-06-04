
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	ll value;
	ll lazy;
};

void buildtree(node *tree, ll *arr, ll s, ll e, ll i) {
	if (s == e) {
		tree[i].value = arr[s];
		tree[i].lazy = 0;
		return;
	}

	tree[i].lazy = 0;
	ll mid = (s + e) / 2;
	buildtree(tree, arr, s, mid, 2 * i);
	buildtree(tree, arr, mid + 1, e, 2 * i + 1);
	tree[i].value = tree[2 * i].value + tree[2 * i + 1].value;
}

void update(node *tree, ll s, ll e, ll i, ll l, ll r, ll inc) {
	if (s > e)return;
	if (tree[i].lazy != 0) {
		tree[i].value += (e - s + 1) * tree[i].lazy;
		if (s != e) {
			tree[2 * i].lazy += tree[i].lazy;
			tree[2 * i + 1].lazy += tree[i].lazy;
		}
		tree[i].lazy = 0;
	}


	if (s > r || e < l)return;

	if (s >= l && e <= r) {
		tree[i].value += (e - s + 1) * inc;
		if (e != s) {
			tree[2 * i].lazy += inc;
			tree[2 * i + 1].lazy += inc;
		}
		return;
	}
	ll mid = (s + e) / 2;
	update(tree, s, mid, 2 * i, l, r, inc);
	update(tree, mid + 1, e, 2 * i + 1, l, r, inc);
	tree[i].value = tree[2 * i].value + tree[2 * i + 1].value;


}

node query(node *tree, ll s, ll e, ll i, ll l, ll r) {
	if (s > e)return{0, 0};
	if (tree[i].lazy != 0) {
		tree[i].value += (e - s + 1) * tree[i].lazy;
		if (s != e) {
			tree[2 * i].lazy += tree[i].lazy;
			tree[2 * i + 1].lazy += tree[i].lazy;
		}
		tree[i].lazy = 0;
	}
	if (s > r || e < l) {
		return {0, 0};
	}
	if (s >= l && e <= r) {
		return tree[i];
	}

	ll mid = (s + e) / 2;
	node ans1 = query(tree, s, mid, 2 * i, l, r);
	node ans2 = query(tree, mid + 1, e, 2 * i + 1, l, r);
	node ans;
	ans.value = ans1.value + ans2.value;
	ans.lazy = ans1.lazy + ans2.lazy;
	return ans;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, c;
		cin >> n >> c;
		ll arr[n] = {0};
		node tree[4 * n];
		buildtree(tree, arr, 0, n - 1, 1);
		while (c--) {
			ll x, y, z;
			cin >> x >> y >> z;
			if (x == 0) {
				ll v;
				cin >> v;
				update(tree, 0, n - 1, 1, y - 1, z - 1, v);
			}
			else {
				node ans = query(tree, 0, n - 1, 1, y - 1, z - 1);
				cout << ans.value << endl;
			}
		}

	}
}
