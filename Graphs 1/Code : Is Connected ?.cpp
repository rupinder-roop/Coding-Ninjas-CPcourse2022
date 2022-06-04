#include<bits/stdc++.h>
using namespace std;

void Is_connect(int **arr,int v,int curr,bool *vis)
{
    queue<int>q;
    vis[curr]=true;
    q.push(curr);
    while(!q.empty()){
        int current=q.front();
        for(int i=0;i<v;i++){
            if(!vis[i] and i!=current and arr[current][i]==1){
                q.push(i);
                vis[i]=true;
            }
        }
        q.pop();
    }
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        
		int v,e;
        cin>>v>>e;
        int **arr=new int*[v];
        for(int i=0;i<v;i++){
            arr[i]=new int[v];
            for(int j=0;j<v;j++){
                arr[i][j]=0;
            }
        }
        
        while(e--){
            int a,b;
            cin>>a>>b;
            arr[a][b]=1;
            arr[b][a]=1;
            
        }
        bool *vis=new bool[v];
        for(int i=0;i<v;i++){
            vis[i]=false;
        }
        Is_connect(arr,v,0,vis);
        int check=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                check=1;
                cout<<"false"<<endl;
                break;
            }
        }
        if(check==0){
            cout<<"true"<<endl;
        }
        
        
    }


    return 0;
}
