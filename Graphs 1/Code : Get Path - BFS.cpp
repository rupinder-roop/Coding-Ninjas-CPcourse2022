#include<bits/stdc++.h>
using namespace std;

void BFS_path(int **arr,int v,int curr,int end,bool *vis){
    
    queue<int> q;
    vis[curr]=true;
    q.push(curr);
    map<int,int>m;
    while(!q.empty()){
        int current=q.front();
        if(current==end){
            break;
        }
        for(int i=0;i<v;i++){
            if(!vis[i] and arr[current][i]==1 and i!=current){
                q.push(i);
                vis[i]=true;
                m[i]=current;
            }
        }
        q.pop();
        if(q.empty()){
            return;
        }
    }
    int i=end;
    cout<<end<<" ";
    while(i!=curr){
        cout<<m[i]<<" ";
        i=m[i];
    }
    cout<<endl;
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
    int start,end;
    cin>>start>>end;
    bool *vis=new bool[v];
    for(int i=0;i<v;i++){
        vis[i]=false;
    }
    BFS_path(arr,v,start,end,vis);
    }
    return 0;
}
