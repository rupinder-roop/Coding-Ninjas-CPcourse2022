#include <bits/stdc++.h>
using namespace std;
#define ll long long int





const int maxval = 100004;
ll mod = 1e9 + 7;

ll BIT[3][maxval + 2];

void update(int x, int i, int val)
{
    while (x <= maxval)
    {
        BIT[i][x] += val;
        BIT[i][x] %= mod;
        x += x & -x;
    }
}
long long query(int x, int i)
{
    long long ans = 0;
    while (x > 0)
    {
        ans += BIT[i][x];
        ans %= mod;
        x -= x & -x;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    ll ans = 0, a, b;
    ll arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        a = query(arr[i] - 1, 0) + query(arr[i] - 1, 2);
        a %= mod;

        b = query(maxval, 1) - query(arr[i], 1) + query(maxval, 2) - query(arr[i], 2);
        b = (b + mod) % mod;
        ans += (a + b) % mod;

        update(arr[i], 0, b);
        update(arr[i], 1, a);
        update(arr[i], 2, 1);

        ans %= mod;
    }
    cout << ans << endl;
}
