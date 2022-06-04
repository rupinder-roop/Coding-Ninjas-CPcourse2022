#include<bits/stdc++.h>
using namespace std;
struct node {
	int power;
	int coward;
	int index;
};

void buildtree(node *arr, node* tree, int start, int end, int treenode) {
	if (start == end) {
		tree[treenode] = arr[start];
		return;
	}



	int mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);

	if (tree[2 * treenode].power > tree[2 * treenode + 1].power) {
		tree[treenode] = tree[2 * treenode];
	}
	else if (tree[2 * treenode].power < tree[2 * treenode + 1].power) {
		tree[treenode] = tree[2 * treenode + 1];
	}
	else {
		if (tree[2 * treenode].coward == tree[2 * treenode + 1].coward) {
			if (tree[2 * treenode].index < tree[2 * treenode + 1].index) {
				tree[treenode] = tree[2 * treenode];
			}
			else {
				tree[treenode] = tree[2 * treenode + 1];
			}
		}
		else if (tree[2 * treenode].coward < tree[2 * treenode + 1].coward) {
			tree[treenode] = tree[2 * treenode];
		}
		else {
			tree[treenode] = tree[2 * treenode + 1];

		}
	}


}



node query(node *arr, node *tree, int start, int end, int left, int right, int treenode) {

	if (start > right || end < left) {
		return {0, 0, 0};
	}
	if (start >= left && end <= right) {
		return tree[treenode];
	}

	int mid = (start + end) / 2;
	node ans1 = query(arr, tree, start, mid, left, right, 2 * treenode);
	node ans2 = query(arr, tree, mid + 1, end, left, right, 2 * treenode + 1);


	if (ans1.power > ans2.power) {
		return ans1;
	}
	else if (ans1.power < ans2.power) {
		return ans2;
	}
	else {
		if (ans1.coward == ans2.coward) {
			if (ans1.index < ans2.index) {
				return ans1;
			}
			else {
				return ans2;
			}
		}
		else if (ans1.coward < ans2.coward) {
			return ans1;
		}
		else {
			return ans2;

		}
	}

}

int main() {
	int n;
	cin >> n;
	node *arr = new node[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].power;
		arr[i].index = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].coward;
	}
	node *tree = new node[4 * n];
	buildtree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		node ans;
		ans = query(arr, tree, 0, n - 1, l - 1, r - 1, 1);
		cout << ans.index + 1 << endl;
	}
}
