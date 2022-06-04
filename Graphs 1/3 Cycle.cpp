#include<iostream>
#include<vector>
using namespace std;


int solve(int n,int m,vector<int> u,vector<int> v)
{
	int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<m;i++){
        int start,end;
        start = u[i] - 1;
        end = v[i] - 1;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(edges[i][j] == 1 && i != j){
               for(int k=0;k<n;k++){
                   if(edges[j][k] == 1 && j != k && i != k){
                       if(edges[i][k] == 1){
                           count++;
                       }
                   }
               }
           }
        }
    }
    
    return count/6;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
