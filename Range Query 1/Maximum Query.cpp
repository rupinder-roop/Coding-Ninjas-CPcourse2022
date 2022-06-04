#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20000;
const int k = 15;
int logst[MAXN + 1];
int st[MAXN][k + 1];
int arr[MAXN];

void pre(int n)
{
    for(int i=2;i<=MAXN;i++)
    {
        logst[i] = logst[i/2] + 1;
    }
    for(int i=0;i<n;i++)
            st[i][0] = arr[i];
    
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i+(1<<j) <= n;i++)
        {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }    
}

int query(int l, int r)
{
    int j = logst[r-l+1];
    int minimum = max(st[l][j], st[r-(1<<j) + 1][j]);
    return minimum;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    pre(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    
}
