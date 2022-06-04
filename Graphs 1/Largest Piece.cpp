#include<bits/stdc++.h>
using namespace std;
const int mex = 1e3 + 1;
int arr[mex][mex];
int dfs(int i, int j, int n, int m, bool visited[][mex]) {
	if (arr[i][j] == 0) {
		return 0;
	}
	visited[i][j] = true;
	if (i >= n || j >= m || i < 0 || j < 0) {
		return 0;
	} int  w = 0, x = 0, y = 0, z = 0;
	if (j + 1 < m && arr[i][j + 1] == 1 && !visited[i][j + 1]) {
		x = 1 + dfs(i, j + 1, n, m, visited);
	}
	if (j - 1 >= 0 && arr[i][j - 1] == 1 && !visited[i][j - 1]) {
		y = 1 + dfs(i, j - 1, n, m, visited);
	}
	if (i + 1 < n && arr[i + 1][j] == 1 && !visited[i + 1][j]) {
		z = 1 + dfs(i + 1, j, n, m, visited);
	}
	if (i - 1 >= 0 && arr[i - 1][j] == 1 && !visited[i - 1][j]) {
		w = 1 + dfs(i - 1, j, n, m, visited);
	}
	return x + y + z + w;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] = s[j] - '0';
			}
		}
		bool visited[mex][mex];
		int maxm = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					maxm = max(maxm, 1 + dfs(i, j, n, n, visited));
				}
			}
		}
		cout << maxm << endl;
	}
}
