#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ip
{
    int x, y, k;
    ll ind;
};
#define f first
#define s second
const int N = 1e6 + 4;
int bit[N];
bool compare(ip a, ip b)
{
    return a.k > b.k;
}
bool compare2(pair<int, int> a, pair<int, int> b)
{
    return a.f > b.f;
}

void update(int a, int x)
{
    for (a; a <= N; a += a & (-a))
        bit[a] += x;
}
int query(int a)
{
    int s = 0;
    for (a; a > 0; a -= a & (-a))
        s += bit[a];

    return s;
}
int main()
{
    int n;
    cin >> n;
    pair<int, int> arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].f;
        arr[i].s = i;
    }
    int q;
    cin >> q;
    ip qr[q+2];
    sort(arr+1, arr + n+1, compare2);
    for (int i = 0; i < q; i++)
    {
        cin >> qr[i].x >> qr[i].y >> qr[i].k;
        qr[i].ind = i;
    }
  
    sort(qr, qr + q, compare);
    // for (auto it:arr){
    // cout << it.f << " " << it.s;
    // cout << endl;
    // }
    // for (int i = 0; i < q;i++){
    // cout << qr[i].x << " " << qr[i].y << " " << qr[i].k <<" "<< qr[i].ind << endl;
    // }
        int ans[q + 2];
    int z = 1;
    for (int i = 0; i < q; i++)
    {

        while (z <=n && qr[i].k < arr[z].f)
        {
            update(arr[z].s, 1);
            z++;
        }
        ans[qr[i].ind] = query(qr[i].y) - query(qr[i].x - 1);
    }

    for (int i = 0; i <q;i++){
        cout << ans[i] << endl;
    }

    return 0;
}
