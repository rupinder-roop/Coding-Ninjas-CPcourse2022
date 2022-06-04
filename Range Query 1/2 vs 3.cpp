#include<bits/stdc++.h>
using namespace std;
#define ll long long

void build(int *tree, int *arr, int s, int e, int i, int* powarr) {
	if (s == e) {
		tree[i] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(tree, arr, s, mid, 2 * i, powarr);
	build(tree, arr, mid + 1, e, 2 * i + 1, powarr);
	tree[i] = (tree[2 * i + 1] + tree[2 * i] * powarr[e - mid]) % 3;
}


void update(int *tree, int *arr, int s, int e, int i, int* powarr, int index) {
	if (s == e) {
		arr[index] = 1;
		tree[i] = 1;
		return;
	}
	int mid = (s + e) / 2;
	if (index > mid) {
		update(tree, arr, mid + 1, e, 2 * i + 1, powarr, index);
	}
	else {
		update(tree, arr, s, mid, 2 * i, powarr, index);
	}
	tree[i] = (tree[2 * i + 1] + tree[2 * i] * powarr[e - mid]) % 3;
}


int query(int *tree, int s, int e, int l, int r, int i, int *powarr) {
	if (s > r || e < l) {
		return 0;
	}

	if (s >= l && e <= r) {
		return (tree[i] * powarr[r - e]) % 3;
	}
	int mid = (s + e) / 2;
	int ans1 = query(tree, s, mid, l, r, 2 * i, powarr);
	int ans2 = query(tree, mid + 1, e, l, r, 2 * i + 1, powarr);
	return (ans1 + ans2) % 3;
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = s[i] - '0';
	}
	int *tree = new int[4 * n];
	int *powarr = new int[100000 + 1];
	powarr[0] = 1;
	for (int i = 1; i < 100000 + 1; i++) {
		powarr[i] = (2 * powarr[i - 1]) % 3;
	}
	build(tree, arr, 0, n - 1, 1, powarr);
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x == 0) {
			int l, r;
			cin >> l >> r;
			cout << query(tree, 0, n - 1, l, r, 1, powarr) << endl;

		}
		else {
			int ind;
			cin >> ind;
			update(tree, arr, 0, n - 1, 1, powarr, ind);
		}
	}
}
