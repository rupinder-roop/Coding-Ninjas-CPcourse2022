#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005, M = 11;
int mod = 5000000;

int BIT[51][N];

int query(int i, int y)
{
	int count = 0;
	for(; y > 0; y -= (y&(-y)))
	{
		count += BIT[i][y]%mod;
		count%=mod;
	}
	return count%mod;
}

void update(int i, int val, int y)
{
	for(; y <= 100001; y += (y&(-y)))
	{
		BIT[i][y] += (val%mod);
		BIT[i][y] %= mod;
	}
}

int32_t main(){
	int n,k;
	cin>>n>>k;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
		arr[i]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int a = j == 1 ? 1:query(j-1, arr[i]-1);
			update(j, a%mod, arr[i]);
			if(j == k)
				ans = (ans+a)%mod;
		}
		
	}
	cout<<ans%mod<<endl;
	delete [] arr;
	return 0;
}
