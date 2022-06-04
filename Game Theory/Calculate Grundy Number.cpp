#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e6+5;

int dp[N];

int getGrundy(int n) {
	if(n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    
	int a = getGrundy(n/2);
	int b = getGrundy(n/3);
	int c = getGrundy(n/6);
    
	int x=0;
	while(x == a || x == b || x == c) {
        ++x;
	}
    return dp[n] = x;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    memset(dp , -1, sizeof(dp));
    
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << getGrundy(n) << endl;
    }
	return 0;
}
