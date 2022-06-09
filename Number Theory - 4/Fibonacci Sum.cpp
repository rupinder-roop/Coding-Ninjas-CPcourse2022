#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

void mult(ll a[][2], ll b[][2])
{
    ll res[2][2];
    memset(res, 0, sizeof res);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = res[i][j];
        }
    }
}
ll helper(ll num)
{
    ll q[2][2] = {{1, 1}, {1, 0}};
    ll w[2][2] = {{1, 0}, {0, 1}};
    while (num)
    {
        if (num & 1)
            mult(w, q);

        mult(q, q);

        num >>= 1;
    }

    return w[0][1];
}

ll fiboSum(ll m, ll n)
{
    return (helper(n + 2) - helper(m + 1) + mod) % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << fiboSum(n, m) << endl;
    }
}
