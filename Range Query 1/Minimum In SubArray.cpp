#include<bits/stdc++.h>
using namespace std;

void buildtree(int *tree, int *arr, int i, int s, int e) {
	if (s == e) {
		tree[i] = arr[s];
		return;
	}

	int mid = (s + e) / 2;
	buildtree(tree, arr, 2 * i, s, mid);
	buildtree(tree, arr, 2 * i + 1, mid + 1, e);
	tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void update(int *tree, int*arr, int i, int s, int e, int idx, int val) {
	if (s == e) {
		tree[i] = val;
		arr[idx] = val;
		return;
	}



	int mid = (s + e) / 2;

	if (idx > mid) {
		update(tree, arr, 2 * i + 1, mid + 1, e, idx, val);
	}
	else {
		update(tree, arr, 2 * i, s, mid, idx, val);
	}

	tree[i] = min(tree[2 * i], tree[2 * i + 1]);

}

int query(int *tree, int i, int s, int e, int l, int r) {

	if (s > r || e < l) {
		return INT_MAX;
	}

	if (s >= l && e <= r) {
		return tree[i];
	}

	int mid = (s + e) / 2;
	int ans1 = query(tree, 2 * i, s, mid, l, r);
	int ans2 = query(tree, 2 * i + 1, mid + 1, e, l, r);
	return min(ans1, ans2);
}

int main() {
	int n, q;
	cin >> n >> q;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tree[4 * n];
	buildtree(tree, arr, 1, 0, n - 1);
	while (q--) {
		char x;
		cin >> x;
		if (x == 'q') {
			int y, z;
			cin >> y >> z;
			y--, z--;
			cout << query(tree, 1, 0, n - 1, y, z) << endl;
		}
		else {
			int y, z;
			cin >> y >> z;
			y--;
			update(tree, arr, 1, 0, n - 1, y, z);
		}
	}
}
