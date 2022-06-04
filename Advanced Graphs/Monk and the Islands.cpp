#include<bits/stdc++.h>
using namespace std;
#define pencho ios_base::sync_with_stdio(0);cin.tie(0); 
#define mod 1000000007
int n;
int dp[10001];
int solve(vector<int>adj[])
{
    queue<int>q;
    dp[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int idx=q.front();
        q.pop();
        for(int i=0;i<adj[idx].size();i++)
        {
            if(dp[adj[idx][i]]==-1)
            {
                dp[adj[idx][i]]=dp[idx]+1;
                q.push(adj[idx][i]);
            }
        }
    }
    return dp[n];
}
int main()
{
    pencho
    int t,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        vector<int>adj[n+1];
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout<<solve(adj)<<endl;
    }
}
