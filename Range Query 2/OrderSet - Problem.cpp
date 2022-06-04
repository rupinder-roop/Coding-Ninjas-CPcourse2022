#include <bits/stdc++.h>

using namespace std;
const int MAX = 2000005;
typedef long long int ll;
int get_count(int idx, int BIT[]) {
  if (idx == 0)
    return 0;
  ll sum = 0;
  while (idx > 0) {
    sum += BIT[idx];
    idx -= idx & (-idx);
  }
  return sum;
}
void updateBIT(int idx, int val, int BIT[]) {
  while (idx < MAX) {
    BIT[idx] += val;
    idx += idx & (-idx);
  }
}
pair < int, bool > b_search(int x, vector < pair < int, int >> & dist, int n) {
  int lo = 0, hi = n - 1, mid, ans = -1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (dist[mid].first == x) {
      return {
        mid,
        true
      };
    } else if (dist[mid].first > x)
      hi = mid - 1;
    else {
      ans = mid;
      lo = mid + 1;
    }
  }
  return {
    ans,
    false
  };
}
int main() {
  int q;
  cin >> q;
  int arr[q];
  vector < int > store;
  vector < char > type;
  for (int i = 0; i < q; i++) {
    char x;
    cin >> x >> arr[i];
    type.push_back(x);
    if (x == 'I') {
      store.push_back(arr[i]);
    }
  }
  sort(store.begin(), store.end());
  vector < pair < int, int >> dist;
  dist.push_back({
    store[0],
    0
  });
  int n = 1;
  for (int i = 1; i < store.size(); i++) {
    if (store[i] != store[i - 1]) {
      dist.push_back({
        store[i],
        0
      });
      n++;
    }
  }
  int BIT[MAX + 2];
  memset(BIT, 0, sizeof(BIT));
  for (int i = 0; i < q; i++) {
    if (type[i] == 'I') {
      pair < int, bool > temp = b_search(arr[i], dist, n);
      if (dist[temp.first].second == 0) {
        dist[temp.first].second = 1;
        updateBIT(temp.first + 1, 1, BIT);
      }
    } else if (type[i] == 'D') {
      pair < int, bool > temp = b_search(arr[i], dist, n);
      if (temp.first != -1 && dist[temp.first].second == 1 && temp.second) {
        updateBIT(temp.first + 1, -1, BIT);
        dist[temp.first].second = 0;
      }
    } else if (type[i] == 'C') {
      pair < int, bool > temp = b_search(arr[i], dist, n);
      if (temp.second)
        printf("%d\n", get_count(temp.first, BIT));
      else if (temp.first != -1)
        printf("%d\n", get_count(temp.first + 1, BIT));
      else
        printf("0\n");
    } else if (type[i] == 'K') {
      int k = arr[i], x = -1;
      bool mno = 0;
      int lo = 1;
      int hi = n;

      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (get_count(mid, BIT) == k && get_count(mid - 1, BIT) != k) {
          mno = 1;
          x = mid;
          break;
        } else if (get_count(mid, BIT) < k) {
          x = mid;
          lo = mid + 1;
        } else
          hi = mid - 1;
      }
      if (!mno)
        printf("invalid\n");
      else
        printf("%d\n", dist[x - 1].first);
    }
  }
  return 0;
}
