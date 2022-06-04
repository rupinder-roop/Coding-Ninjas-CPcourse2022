#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
	ll odd;
	ll even;
};

void buildtree(ll *arr, node *tree, ll start, ll end, ll treenode) {
	if (start == end) {
		if (arr[start] % 2) {
			tree[treenode].odd = 1;
			tree[treenode].even = 0;
		}
		else {
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		return;
	}

	ll mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);

	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;


}


void update(node * tree, ll *arr, ll start, ll end, ll treenode, ll index, ll value) {
	if (start == end) {
		arr[index] = value;
		if (value % 2) {
			if (tree[treenode].odd == 0) {
				swap(tree[treenode].odd, tree[treenode].even);
			}

		}
		else {
			if (tree[treenode].even == 0) {
				swap(tree[treenode].odd, tree[treenode].even);
			}
		}


		return;
	}







	ll mid = (start + end) / 2;
	if (index > mid) {
		update(tree, arr, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else {
		update(tree, arr, start, mid, 2 * treenode, index, value);
	}

	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;


}

node query(node *tree, ll start, ll end, ll left, ll right, ll treenode) {
	if (start > right || end < left) {
		return {0, 0};
	}

	if (start >= left && end <= right) {
		return tree[treenode];
	}
	ll mid = (start + end) / 2;
	node ans1 = query(tree, start, mid, left, right, 2 * treenode);
	node ans2 = query(tree, mid + 1, end, left, right, 2 * treenode + 1);

	node ans;
	ans.even = ans1.even + ans2.even;
	ans.odd = ans1.odd + ans2.odd;
	return ans;
}


int main()
{

	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	node *tree = new node[4 * n];
	buildtree(arr, tree, 0, n - 1, 1);
	ll q;
	cin >> q;
	while (q--) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (x == 0) {
			update(tree, arr, 0, n - 1, 1, y - 1, z);
		}
		else if (x == 1) {
			cout << query(tree, 0, n - 1, y - 1, z - 1, 1).even << endl;
		}
		else {
			cout << query(tree, 0, n - 1, y - 1, z - 1, 1).odd << endl;
		}
	}
}
